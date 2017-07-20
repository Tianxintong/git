#include"./utili.h"
#include<iostream>
#include<stdlib.h>
#include<deque>
#include<string.h>
using namespace std;
#include"./bigint.h"

	int sockfd;
	char buffer[MAX_BUFFER_SIZE];
	int pipefd[2];
	u_char opt,tmp;
	BigInt b1(0);
	BigInt b2(0);
	BigInt b3(0);

void SendData()
{
	int ret;
	int len = b1.size();
	ret = send(sockfd,(const void *)&opt,1,0);
	send(sockfd,(const void *)&len,sizeof(size_t),0);
	//@@@
	
}		
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

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	assert(sockfd >= 0);
	if(connect(sockfd, (struct sockaddr*)&sever_address,sizeof(sever_address))<0)
	{
		printf("Connection Failed.\n");
		close(sockfd);
		return 1;
	}
	
	struct pollfd fds[2];
//	fds[0].fd = 0;//stdin
//	fds[0].events = POLLIN;
//	fds[0].revents = 0;
	fds[1].fd = sockfd;
	fds[1].events = POLLIN|POLLHUP;
	fds[1].revents = 0;
	
	int res = pipe(pipefd);
	assert(res!=-1);
		

	printf("Input OPT:\n");
	scanf("%c",&opt);
	flush(stdin);
	b1.clear();
	b2.clear();
	printf("Input first opt number:\n");
	while(scanf("%c",&tmp) )
	{
			if(tmp  == '\n')
			break;
			b1.push_back( tmp );
	}
	flush(stdin);
	printf("Input Second opt number\n");
	while(scanf("%c",&tmp))
	{
			if(tmp  == '\n')
			break;
			b2.push_back( tmp );
	}
	cout<<flush;
	switch(opt)
	{
		case'+':
	//		SendData();

			break;
		case '-':
	//		SendData();
			break;
		default:
		break;
	}

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
		//来自服务器的计算结果

		/*
			memset(buffer, '\0',MAX_BUFFER_SIZE);
			ret= recv(sockfd, buffer, MAX_BUFFER_SIZE,0);
			if(ret == 0)
			{
				printf("sever close connection.\n");
				break;
			}
			printf("msg>:%s\n",buffer);
		*/
		}
		else if(fds[1].revents & POLLHUP)
		{
			printf("sever close the connection.\n");
			break;
		}
/*		if(fds[0].revents&POLLIN)
		{
		//来自stdin的数据
	
			ret = splice(0,NULL,pipefd[1],NULL,32768,SPLICE_F_MORE|SPLICE_F_MOVE);
	//		if(ret<=0)
	//		printf("NO  data from stdin\n");
			ret = splice(pipefd[0],NULL,sockfd,NULL,32768,SPLICE_F_MORE|SPLICE_F_MOVE);
		
		
		}
*/
	}
	close(sockfd);
	return 0;
}
