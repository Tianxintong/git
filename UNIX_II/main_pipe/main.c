#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<assert.h>  
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include<wait.h>
#define MAXLEN 1024

void client(int readfd,int writefd)
{
	size_t len;
	ssize_t n;
	char buff[MAXLEN];

	void * q = fgets(buff,MAXLEN,stdin);
	if(q == NULL)
	{
		printf("fgets fail.\n");
		return;
	}
	len = strlen(buff);
	if(buff[len-1] == '\n')
	{
		len--;
	}
	write(writefd,buff,len);
	while((n = read(readfd,buff,MAXLEN)) > 0)
	{
		write(STDOUT_FILENO,buff,n);
	}

}
void server(int readfd,int writefd)
{
	int fd;
	ssize_t n;
	char buff[MAXLEN];

	if( (n=read(readfd,buff,MAXLEN))==0)
	{
		printf("end-of-file while reading patname.\n");
		exit(0);
	}
	buff[n] = '\0';

	if( (fd = open(buff,O_RDONLY))<0)
	{
		snprintf(buff+n,sizeof(buff)-n,": can't open,%s\n",strerror(errno));
		n = strlen(buff);
		int ret = write(writefd,buff,n);
		assert(ret >= 0);
	}
	else
	{
		while((n = read(fd,buff,MAXLEN))>0)
		write(writefd,buff,n);
		close(fd);
	}
}
int main(int argc,char** argv)
{
	int pipe1[2],pipe2[2];
	pid_t childpid;

	int ret = pipe(pipe1);
	assert(ret!=-1);
	ret = pipe(pipe2);
	assert(ret!=-1);

	childpid = fork();
	assert(childpid!=-1);
	if(childpid == 0)
	{
		close(pipe1[1]);
		close(pipe2[0]);

		server(pipe1[0],pipe2[1]);
		exit(0);
	}

	close(pipe1[0]);
	close(pipe2[1]);

	client(pipe2[0],pipe1[1]);

	waitpid(childpid,NULL,0);
	exit(0);
}
