#include"../utili.h"
#include"./utili.h"
int main(int argc,char **argv)
{
	int readfd,writefd;

	writefd = open(FIFO1,O_WRONLY,0);
	readfd = open(FIFO2,O_RDONLY,0);

	client(readfd,writefd);

	close(readfd);
	close(writefd);

	unlink(FIFO2);
	unlink(FIFO1);
	exit(0);
}
