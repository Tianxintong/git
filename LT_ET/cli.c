#include"./utili.h"
#define MAX_BUFFER_SIZE 50
int main(int argc,char *argv[])
{
	if(argc<=2)
	{
		printf("usage:%s  IP  Port number\n",basename(argv[0]));
		return 1;
	}
	const char * ip = argv[1];
	int port = atoi(argv[2]);

	struct sockaddr_in server_address;
	bzero(&server_address,sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(port);
	inet_pton(AF_INET,ip,&server_address.sin_addr);

	int sock = socket(AF_INET,SOCK_STREAM,0);
	assert(sock >= 0);
	socklen_t len = sizeof(server_address);
	int ret = connect(sock,(struct sockaddr*)&server_address,len);
	assert(ret>=0);
	
	char buf[MAX_BUFFER_SIZE];

	while(1)
	{
		scanf("%s",buf);
		buf[strlen(buf)]='\0';
	//	if(strncmp(buf,"close",5)==0)
		{
	//		break;
		}
		ret = send(sock,buf,strlen(buf)+1,0);
	}
	close(sock);
	return 1;
}
