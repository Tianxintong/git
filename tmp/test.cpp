#include <unistd.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<errno.h>

int main()
{
	int fd = open("test.txt",O_APPEND);
	printf("fd = %d\n",fd);
	char a[] = "this is  a test.c";
	int ret = write(fd,a,strlen(a)+1);
	printf("write ret = %d\n",ret);
	printf("%d\n",errno);
	close(fd);
	return 0;
}
