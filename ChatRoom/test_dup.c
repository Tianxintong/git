#include"./utili.h"

int main()
{
	int sockSer = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in adress;
	adress.sin_family = AF_INET;
	adress.sin_port = htons(9090);
	adress.sin_addr.s_addr = inet_addr("127.0.0.1");

	socklen_t len = sizeof(struct sockaddr);
	bind(sockSer,(struct sockaddr*)&adress,len);
	listen(sockSer,5);

	struct sockaddr_in  addrCli;
	int sockConn = accept(sockSer,(struct sockaddr*)&addrCli, &len);
	if(sockConn == -1)
	{
		printf("accept erro");
	}
	else
	{
	/*
		while(1)
		{
			close(STDOUT_FILENO);
			dup(sockConn);
			printf("abcdef");
			sleep(50);
		//	close(sockConn);
		}
	*/

//	sendfile();  网络传输文件的函数
//
	}
	return 0;
}
