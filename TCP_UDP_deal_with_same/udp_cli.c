#include"./utili.h"
#define MAX_BUFFER_SIZE 512
int main(const int argc,char *argv[])
{
	if(argc<=2)
	{
		printf("usage:%s IP  Port  \n",argv[0]);
		return 1;
	}
	struct sockaddr_in address;
	bzero(&address,sizeof(address));
	address.sin_family = AF_INET;
	address.sin_port = atoi(argv[2]);
	address.sin_addr.s_addr = inet_addr("127.0.0.1");

	int clientfd = socket(AF_INET,SOCK_DGRAM,0);
	assert(clientfd>=0);
	int ret;
	ret = connect(clientfd,(struct sockaddr*)&address,sizeof(address));
	if(ret<0)
	{
		printf("connect Fail.\n");
		exit(1);
	}
	
	socklen_t len  = sizeof(address);
	char buffer[MAX_BUFFER_SIZE];
	
	while(1)
	{
	scanf("%s",buffer);
	//	ret = recvfrom(clientfd,buffer,MAX_BUFFER_SIZE,0,&from_address,&from_len);
	//	if(ret>0)
	//	{
	memset(buffer,'\0',MAX_BUFFER_SIZE);
			sendto(clientfd,buffer,MAX_BUFFER_SIZE,0,(struct sockaddr*)&address,len);
			ret = recvfrom(clientfd,buffer,MAX_BUFFER_SIZE,0,(struct sockaddr*)&address,&len);
			if(ret>0)
			printf("Msg from  myself:> %s\n",buffer);
	//	}
	}
	close(clientfd);
}
