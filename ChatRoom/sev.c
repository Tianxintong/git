#include"./utili.h"

#define MAX_LISTEN_QUEUE 5
#define USER_LIMIT 5
#define FD_LIMIT 65535

typedef struct client_data
{
	struct sockaddr_in address;
	char *write_buf;
	char buf[MAX_BUFFER_SIZE];
}client_data;
int setnonblocking(int fd)
{
	int old_option = fcntl(fd,F_GETFL);
	int new_option = old_option|O_NONBLOCK;
	fcntl(fd,F_SETFL,new_option);
	return old_option;
}
int main(const int argc,char *argv[])
{
	if(argc<=2)
	{
		printf("usage: %s ip_address Port_munber\n",argv[0]);
		return 1;
	}

	const char *ip = argv[1];
	int port = atoi(argv[2]);

	struct  sockaddr_in sever_address;
	bzero(&sever_address,sizeof(sever_address));
	sever_address.sin_family = AF_INET;
	sever_address.sin_port = htons(port);
	inet_pton(AF_INET,ip,&sever_address.sin_addr);

	int listenfd = socket(AF_INET,SOCK_STREAM, 0);
	assert(listenfd>=0);

	int ret = bind(listenfd,(struct sockaddr*)&sever_address,sizeof(sever_address));
	assert(ret!=-1);

	ret = listen(listenfd, MAX_LISTEN_QUEUE);
	assert(ret!= -1);

	struct pollfd fds[USER_LIMIT+1];
	client_data* users = (client_data*)malloc(sizeof( client_data)*FD_LIMIT);//将以socket的值将用来索引（作为数组的下标）

	int user_count = 0;
	int i=0;
	for(i=1;i<=USER_LIMIT;++i)
	{
		fds[i].fd = -1;
		fds[i].revents = 0;
	}
	fds[0].fd = listenfd;
	fds[0].events = POLLIN|POLLERR;
	fds[0].revents = 0;
	while(1)
	{
		ret = poll(fds,user_count+1,-1);
		if(ret<0)
		{
			printf("poll Failed.\n");
			break;
		}
	for(i=0;i<user_count+1;++i)
	{
		if(fds[i].fd == listenfd&& (fds[i].revents & POLLIN))
		{
			struct sockaddr_in client_address;
			socklen_t client_addrlen = sizeof(client_address);
			int connfd = accept(listenfd,(struct sockaddr*)&client_address, &client_addrlen);
			if(connfd < 0)
			{
				printf("erron is %d\n",errno);
				continue;
			}
			if(user_count >= USER_LIMIT)
			{
				const char *info = "too many users\n";
				printf("%s",info);
				send(connfd,info,strlen(info)+1,0);
				close(connfd);
				continue;
			}
			user_count++;
			users[connfd].address = client_address;
			setnonblocking( connfd );
			fds[user_count].fd = connfd;
			fds[user_count].events = POLLIN|POLLERR|POLLHUP;
			fds[user_count].revents = 0;
			printf("comes a new user,now have %d users \n",user_count);
		}
		else if(fds[i].revents & POLLERR)
		{
			printf("get an error from %d\n",fds[i].fd);
			char errors[100];
			memset(errors,'\0',100);
			socklen_t len = sizeof(errors);
			if(getsockopt(fds[i].fd, SOL_SOCKET,SO_ERROR,&errors,&len)<0)
			printf("get socket option filed.\n");
			continue;
		}
		else if(fds[i].revents&POLLHUP)
		{
			printf("client close connection\n");
			users[fds[i].fd] = users[fds[user_count].fd];
			close(fds[i].fd);
			fds[i] = fds[user_count];
			i--;
			user_count--;
		}
		else if(fds[i].revents&POLLIN)
		{
			int connfd =fds[i].fd;
			memset(users[connfd].buf,'\0',MAX_BUFFER_SIZE);
			ret = recv(connfd,users[connfd].buf,MAX_BUFFER_SIZE,0);
			printf("get %d bytes of client data %s frome %d\n",ret,users[connfd].buf,connfd);
			if(ret<0)
			{
				if(errno !=EAGAIN)
				{
					close(connfd);
					users[fds[i].fd] = users[fds[user_count].fd];
					fds[i] = fds[user_count];
					--user_count;
					--i;
				}
			}
			else if(ret==0)
			{
				printf("a client close.\n");
				users[fds[i].fd] = users[fds[user_count].fd];
				close(fds[i].fd);
				fds[i] = fds[user_count];
				--i;
				user_count--;
			}
			else 
			{
				//接收到客户数据，则通知其他socket准备写数据
				int j=0;
				for(j=1;j<=user_count;++j)
				{
					if(fds[j].fd == connfd)
						continue;
					fds[j].events |= ~POLLIN;
					fds[j].events |= POLLOUT;
					users[fds[j].fd].write_buf = users[connfd].buf;
				}
			}
		}
		else if(fds[i].revents&POLLOUT)
		{
			int connfd = fds[i].fd;
			if(!users[connfd].write_buf)
			{
			fds[i].events &=~POLLOUT;
			fds[i].events &=POLLIN;
				continue;
			}
			ret = send(connfd,users[connfd].write_buf,MAX_BUFFER_SIZE,0);
			users[connfd].write_buf = NULL;
			fds[i].events &=~POLLOUT;
			fds[i].events &=POLLIN;

		}
	}
	}

	free (users);
	close(listenfd);
	return 0;
}
