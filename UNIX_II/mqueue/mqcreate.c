#include"../utili.h"


int main(int argc,char **argv)
{
	int c,flags;
	mqd_t mqd;

	flags = O_RDWR|O_CREAT;
	while((c=getopt(argc,argv,"e"))!=-1)
	{
		switch(c)
		{
			case 'e':
			flags |= O_EXCL;
			break;
		}
	}
	if(optind != argc-1)
	{
		printf("usage:mqcreate [-e] <name>");
		exit(0);
	}
	mqd = mq_open(argv[optind],flags,FILE_MODE,NULL);
	if(mqd == -1)
	printf("mq_opem Fail. errno = %d\n",errno);
	assert(mqd!=-1);

	mq_close(mqd);
	exit(0);
}
