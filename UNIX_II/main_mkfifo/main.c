#include"../utili.h"

#define FIFO1 "./fifo.1"
#define FIFO2 "./fifo.2"
#define FILE_MODE  S_IFIFO | 0666 
int main(int argc,char **argv)
{
	int readfd,writefd;
	pid_t childpid;

	if((mkfifo(FIFO1,FILE_MODE)<0)&&(errno!=EEXIST))
	{
		printf("can't create %s\n",FIFO1);
		exit(1);
	}
	if((mkfifo(FIFO2,FILE_MODE)<0)&&(errno!=EEXIST))
	{
		unlink(FIFO1);
		printf("can't create %s\n",FIFO2);
	}
	childpid = fork();
	assert(childpid>=0);
	if(childpid ==0)
	{
		readfd = open(FIFO1,O_RDONLY,0);
		writefd = open(FIFO2,O_WRONLY,0);

		server(readfd,writefd);
		exit(0);
	}
	writefd = open(FIFO1,O_WRONLY,0);
	readfd = open(FIFO2,O_RDONLY),0;

	client(readfd,writefd);

	waitpid(childpid,NULL,0);

	close(readfd);
	close(writefd);

	unlink(FIFO1);
	unlink(FIFO2);

	exit(0);
}
