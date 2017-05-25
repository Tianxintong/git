#include"../utili.h"
#include"./utili.h"
int main(int argc,char **argv)
{
	int readfd,writefd;

	if((mkfifo(FIFO1,S_IFIFO | 0666 )<0)&&(errno!=EEXIST))
	{
		printf("can't create %s\n",FIFO1);
		exit(0);
	}
	if((mkfifo(FIFO2,S_IFIFO|0666)<0)&&(errno!=EEXIST))
	{
		unlink(FIFO1);
		printf("can't create %s\n",FIFO2);
		exit(0);
	}

	readfd = open(FIFO1,O_RDONLY,0);
	writefd = open(FIFO2,O_WRONLY,0);

	server(readfd,writefd);
	exit(0);
}
