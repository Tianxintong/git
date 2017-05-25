#include<unistd.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/wait.h>


extern int errno;
void client(int ,int);
void sever(int,int);

int main(int argc,char **argv)
{
	int pipe1[2],pipe2[2];
	pid_t childpid;

	int ret = pipe(pipe1);
	if(ret == -1)
	{
		printf("errno = %d\n",errno);
		return 1;
	}
	ret = pipe(pipe2);
	if(ret == -1)
	{
		printf("errno = %d\n",errno);
		return 1;
	}
	childpid = fork();
	assert(childpid != -1);
	if(childpid == 0)
	{
		close(pipe1[1]);
		close(pipe2[0]);
		sever(pipe1[0],pipe2[1]);
		exit(0);
	}
	close(pipe1[0]);
	close(pipe2[1]);
	client(pipe2[0],pipe1[1]);
	waitpid(childpid,NULL,0);
	exit(0);
	
}

void client(int readfd,int writefd)
{
	size_t len;
	ssize_t n;
	char buf[MAXLEN];

	fgets(buff,MAXLEN,stdin);
	len = strlen(buff);
	if(buff[len-1] == '\n')
	len--;
	
	int ret = =write(writefd,buff ,len);
	if(ret < 0)
	if(ret<0)
	{
		printf("write fail.errno = %d\n",errno);
		return;
	}
	while((n = read(readfd,buff,MAXLEN))>0)
	{
		write(STDOUT_FILENO,buff,n);
	}
}

void sever(int readfd,int writefd)
{
	int fd;
	ssize_t n;
	char buf[MAXLEN+1];
	int ret;

	if((n = read(readfd,buff,MAXLEN))==0)
	{
		printf("end of file while read pathname\n");
		return 1;
	}
	buff[n] = '\0';
	if((fd = open(buff,O_RDONLY)) < 0)
	{
		snprintf(buff+n,sizeof(buff) - n,":can't open %s",strerror(errno));
		ret = write(writefd,buff,n);
		if(ret == -1)
		{
			printf("write fail,errno =%d\n",errno);
			return 1;
		}
	}
	else
	{
		while((n = read(fd,buff,MAXLEN))>0)
		{
			ret = write(writefd,buff,n);
			if(ret == -1)
			{
				printf("write fail,errno = %d\n",errno);
				return 1;
			}
			
		}
		close(fd);
	}
}
