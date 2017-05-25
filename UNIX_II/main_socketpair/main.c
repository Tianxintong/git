#include"../utili.h"
#include<sys/socket.h>

int main(int argc,char **argv)
{
	int fd[2],n;
	char c;
	pid_t childpid;

	int ret = socketpair(AF_UNIX,SOCK_STREAM,0,fd);
	assert(ret!=-1);

	childpid = fork();
	assert(childpid >= 0);

	if(childpid == 0)
	{
		sleep(3);
		if( (n =read(fd[0],&c,1))!=1)
		{
			printf("child: read return %d\n",n);
			return 1;
		}
		printf("child read %c\n",c);
		write(fd[0],"c",1);
		exit(0);
	}
	write(fd[1],"p",1);
	if((n = read(fd[1],&c,1))!=1)
	{
		printf("parent: read return %d\n",n);
		return 1;
	}
	printf("parent read %c\n",c);
	exit(0);

}

