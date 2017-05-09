#include"./utili.h"

#define MAX_EVENT_NUMBER 1024
#define MAX_BUFFER_SIZE 10
#define   bool int
int setnonblocking(int fd)
{
	int old_option = fcntl(fd,F_GETFL);
	int new_option = old_option|O_NONBLOCK;
	fcntl(fd,F_SETFL,new_option);
	return old_option;
}
int addfd(int epollfd,int fd, bool enable_et)
{
	struct epoll_event event;
	event.data.fd = fd;
	event.events = EPOLLIN;
	if(enable_et)
	{
		event.events |= EPOLLET;
	}
	epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event);
	setnonblocking(fd);
}
void lt(struct epoll_event *events,int number,int epollfd,int sock)
{
	int i=0;
	for(;i<number;++i)
	{
		char buf[MAX_BUFFER_SIZE];
		int sockfd = events[i].data.fd;
		if(sockfd == sock)
		{
			struct sockaddr_in client_address;
			socklen_t len = sizeof(client_address);
			int connfd = accept(sock,(struct sockaddr*)&client_address,&len);
			if(connfd<0)
			{
				printf("accept Fail.\n");
				continue;
			}
			addfd(epollfd,connfd,0);
		}
		else if(events[i].events == EPOLLIN)
		{
		//只要socket缓冲区中还有未读出的数据，这段代码就要被触发，重复触发
			printf("event trigger once.\n");
			memset(buf,'\0',MAX_BUFFER_SIZE);
			int ret = recv(sockfd,buf,MAX_BUFFER_SIZE,0);
			if(ret<=0)
			{
				close(sockfd);
				continue;
			}
			printf("get %d bytes of content : %s \n",ret,buf);
		}
		else
		{
			printf("something else happen!!\n");
		}
	}
}

void et(struct epoll_event* events,int number,int epollfd,int sock)
{
	int i=0;
	char buf[MAX_BUFFER_SIZE];
	for(;i<number;++i)
	{
		int sockfd = events[i].data.fd;
		if(sockfd == sock)
		{
			struct sockaddr_in client_address;
			 socklen_t len = sizeof(client_address);
			int connfd = accept(sockfd,(struct sockaddr*)&client_address,&len);
			if(connfd<0)
			{
				printf("accept client fail.\n");
				continue;
			}
			addfd(epollfd,connfd,1);
		}
		else if(events[i].events & EPOLLIN)//这段代码只会触发一次，一次读出全部数据
		{
			printf("event trigger once.\n");
			while(1)
			{
				memset(buf,'\0',MAX_BUFFER_SIZE);
				int ret = recv(sockfd,buf,MAX_BUFFER_SIZE,0);
				if(ret<0)
				{
					if(errno == EAGAIN ||errno == EWOULDBLOCK)
					{
						printf("read later.\n");
						break;
					}
					close(sockfd);
					break;
				}
				else if(ret == 0)
				{
					close(sockfd);
				}
				else
				{
					printf("get %d bytes of content : %s\n",ret,buf);
				}
			}
		}
		else
		{
			printf("something else happened!!!\n");
		}
	}
}
int main(int argc,char *argv[])
{
	if(argc<=2)
	{
		printf("usage:%s IP  port_number \n",basename(argv[0]));
		return 1;
	}
	const char *ip = argv[1];
	int port = atoi(argv[2]);

	int ret;
	struct sockaddr_in address;
	bzero(&address,sizeof(address));
	address.sin_family = AF_INET;
	address.sin_port = htons(port);
	inet_pton(AF_INET,ip,&address.sin_addr);

	int sock = socket(AF_INET,SOCK_STREAM,0);
	assert(sock>=0);

	ret = bind(sock,(struct sockaddr*)&address,sizeof(address));
	assert(ret != -1);

	ret = listen(sock,5);
	assert(ret != -1);

	struct epoll_event events[MAX_EVENT_NUMBER];
	int epollfd = epoll_create(5);
	assert(epollfd!=-1);

	addfd(epollfd,sock,1);
	while(1)
	{
		ret = epoll_wait(epollfd,events,MAX_EVENT_NUMBER,-1);
		if(ret<0)
		{
			printf("epoll failed.\n");
			break;
		}
		lt(events,ret,epollfd,sock);
	//	et(events,ret,epollfd,sock);

	}
	close(sock);
	return  0;
}
