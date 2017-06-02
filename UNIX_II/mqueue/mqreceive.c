#include"../utili.h"

int main(int argc,char **argv)
{
	int c,flags;
	mqd_t mqd;
	ssize_t n;
	uint_t prio;
	void *buff;
	struct mq_attr attr;

	flags = O_RDONLY;

	while((c = getopt(argc,argv,"n"))!=-1)
	{
		switch(c)
		{
			case 'n':
			flags |= O_NONBLOCK;
			break;
		}
	}
	if(optind != argc-1)
	{
		printf("usage: mqreceive [-n] <name> \n");
		exit(0);
	}
	mqd = mq_open(argv[optind],flags);
	mq_getattr(mqd,&attr);

	buff = (char *)malloc(attr.mq_msgsize);

	n = mq_receive(mqd,buff,attr.mq_msgsize,&prio);
	if(n==-1)
	{
		printf("mq_receive Fail.errno = %d\n",errno);
		exit(0);
	}
	printf("read %ld bytes ,prioroty = %u\n",(long)n,prio);
	exit(0);
}
