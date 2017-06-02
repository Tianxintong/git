#include"../utili.h"

int main(int argc,char **argv)
{
	mqd_t mqd;
	struct mq_attr attr;

	if(argc!=2)
	{
		printf("usage: mqgetattr <name>\n");
		exit(0);
	}
	mqd = mq_open(argv[1],O_RDONLY);
	assert(mqd!=-1);
	int ret = mq_getattr(mqd,&attr);
	if(ret == -1)
	{
		printf("mq_getattr Fail. errno = %d\n",errno);
		exit(0);
	}
	printf("max #msgs = %ld,max #bytes/msg = %ld, #currently on queue  = %ld\n",attr.mq_maxmsg,attr.mq_msgsize,attr.mq_curmsgs);
	mq_close(mqd);
	exit(0);
	
}
