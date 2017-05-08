#include"./utili.h"

#define MAX_EVENT_NUMBER 1024
#define TCP_BUFFER_SIZE 512
#define UDP_BUFFER_SIZE 1024

int setnonblocking(int fd)
{
	int old_option = fcntl(fd,F_GETFL);
	int new_option = old_option|O_NONBLOCK;
	fcntl(fd,F_SETFL,new_option);
	return old_option;
}
int addfd(int epollfd,int fd)
{
	struct epoll_event event;
	event.data.fd = fd;
	event.events = EPOLLIN|EPOLLET;
	epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event);
	setnonblocking(fd);
}

int main(int argc , char* argv[])
{
	if(argc<=2)
	{
		printf("usage:%s IP_address  Port NUmber.\n",argv[0]);
		return 1;
	}
	const char *ip = argv[1];
	int port = atoi(argv[2]);

	int ret = 0;
	struct sockaddr_in server_address;
	bzero(&server_address,sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(port);
	inet_pton(AF_INET,ip,&server_address.sin_addr);

	int listenfd = socket(AF_INET,SOCK_STREAM,0);//创建tcp套接字
	assert(listenfd>=0);

	ret = bind(listenfd,(struct sockaddr*)&server_address,sizeof(server_address));
	assert(ret!=-1);

	ret = listen(listenfd,5);
	assert(ret!=-1);

	bzero(&server_address,sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(port);
	inet_pton(AF_INET,ip,&server_address.sin_addr);
	int udpfd = socket(AF_INET,SOCK_DGRAM,0);
	assert(udpfd>=0);

	ret = bind(udpfd,(struct sockaddr*)&server_address,sizeof(server_address));
	assert(ret!=-1);

	struct epoll_event events[MAX_EVENT_NUMBER];
	int epollfd = epoll_create(5);
	assert(epollfd!=-1);
	addfd(epollfd,listenfd);
	addfd(epollfd,udpfd);

	while(1)
	{
		int number = epoll_wait(epollfd,events,MAX_EVENT_NUMBER,-1);
		if(number<0)
		{
			printf("epoll_wait Fail.\n");
			break;
		}
		for(int i=0;i<number;++i)
		{
			int sockfd = events[i].data.fd;
			if(sockfd == listenfd)
			{
				struct sockaddr_in client_address;
				socklen_t len = sizeof(struct sockaddr_in);
				int connfd = accept(listenfd,(struct sockaddr*)&client_address,&len);
				addfd(epollfd,connfd);
			}
			else if(sockfd == udpfd)
			{
				char buf[UDP_BUFFER_SIZE];
				memset(buf,'\0',UDP_BUFFER_SIZE);
				struct sockaddr_in client_address;
				socklen_t len = sizeof(client_address);
				ret = recvfrom(udpfd,buf,UDP_BUFFER_SIZE-1,0,(struct sockaddr*)&client_address,&len);
				if(ret>0)
				{
					sendto(udpfd,buf,UDP_BUFFER_SIZE,0,(struct sockaddr*)&client_address,len);
				}
			}
			else if(events[i].events & EPOLLIN)
			{
				char buf[TCP_BUFFER_SIZE];
				while(1)
				{
					memset(buf,'\0',TCP_BUFFER_SIZE);
					ret = recv(sockfd,buf,TCP_BUFFER_SIZE-1,0);
					if(ret<0)
					{
						if((errno == EAGAIN)||(errno == EWOULDBLOCK))
						{
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
						send(sockfd,buf,ret,0);
					}
				}
			}
			else
			{
				printf("someting else happened.\n");
			}
		}
	}
	close(listenfd);
	return 0;
}
