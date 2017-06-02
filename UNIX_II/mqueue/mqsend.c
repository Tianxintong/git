#include"../utili.h"

int main(int argc,char **argv)
{
	mqd_t mqd;
	void *ptr;
	size_t len;
	uint_t prio;
	if(argc!=4)
	{
		printf("usage: mqsend <name> <#bytes> <priority>\n");
		exit(0);
	}
	len = atoi(argv[2]);
	prio = atoi(argv[3]);

	mqd = mq_open(argv[1],O_WRONLY);
	if(mqd == -1)
	{
		printf("mq_open Fail. errno = %d\n",errno);
		exit(0);
	}
	ptr = (char*)malloc(sizeof(char)*len);
	bzero(ptr,sizeof(char)*len);
	int ret = mq_send(mqd,ptr,len,prio);
	if(ret == -1)
	{
		printf("mq_send Fail. errno = %d\n",errno);
		exit(0);
	}
	exit(0);


}
