#include"../utili.h"

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("usage: mq_unlink <name>\n");
		exit(0);
	}
	int ret = mq_unlink(argv[1]);
	if(ret == -1)
	printf("mq_unlink Fail.!!  errno = %d\n",errno);
	exit(0);
}
