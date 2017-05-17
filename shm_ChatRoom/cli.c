#include"./utili_cli.h"

int main(int argc,char *argv[])
{
	if(argc<=2)
	{
		printf("usage: %s ip_address port_number\n",basename(argv[0]));
		return 1;
	}
	const char *ip=argv[1];
	int port = atoi(argv[2]);

	struct sockaddr_in sever_address;
	bzero( &sever_address,sizeof(sever_address));
	sever_address.sin_family = AF_INET;
	sever_address.sin_port = htons(port);
	inet_pton(AF_INET, ip, &sever_address.sin_addr);

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	assert(sockfd >= 0);
	if(connect(sockfd, (struct sockaddr*)&sever_address,sizeof(sever_address))<0)
	{
		printf("Connection Failed.\n");
		close(sockfd);
		return 1;
	}

	struct pollfd fds[2];
	fds[0].fd = 0;//stdin
	fds[0].events = POLLIN;
	fds[0].revents = 0;
	fds[1].fd = sockfd;
	fds[1].events = POLLIN|POLLHUP;
	fds[1].revents = 0;
	
	char buffer[MAX_BUFFER_SIZE];
	int pipefd[2];
	int res = pipe(pipefd);
	assert(res!=-1);

	while(1)
	{
		int ret = poll(fds, 2, -1);
		if(ret<0)
		{
			printf("poll Failed.\n");
			break;
		}
		if(fds[1].revents & POLLIN)
		{
			memset(buffer, '\0',MAX_BUFFER_SIZE);
			ret= recv(sockfd, buffer, MAX_BUFFER_SIZE,0);
			if(ret == 0)
			{
			//	printf("sever close connection.\n");
			//	break;
		  		continue;
			}
			if(ret!=0)
			printf("msg>:%s\n",buffer);
		}
		else if(fds[1].revents & POLLHUP)
		{
			printf("sever close the connection.\n");
			break;
		}
		if(fds[0].revents&POLLIN)
		{
			ret = splice(0,NULL,pipefd[1],NULL,32768,SPLICE_F_MORE|SPLICE_F_MOVE);
	//		if(ret<=0)
	//		printf("NO  data from stdin\n");
			ret = splice(pipefd[0],NULL,sockfd,NULL,32768,SPLICE_F_MORE|SPLICE_F_MOVE);
		}
	}
	close(sockfd);
	return 0;
}
