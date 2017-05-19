#include<sys/socket.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<errno.h>
static const int CONTROL_LEN = CMSG_LEN(sizeof(int));

void send_fd(int fd,int fd_to_send)
{
	struct iovec iov[1];
	struct msghdr msg;
	char buf[0];

	iov[0].iov_base = buf;
	iov[0].iov_len = 1;
	msg.msg_name = NULL;
	msg.msg_namelen = 0;
	msg.msg_iov = iov;
	msg.msg_iovlen = 1;

	struct cmsghdr cm;
	cm.cmsg_len = CONTROL_LEN;
	cm.cmsg_level = SOL_SOCKET;
	cm.cmsg_type = SCM_RIGHTS;
	*(int*)CMSG_DATA(&cm) = fd_to_send;
	msg.msg_control = &cm;
	msg.msg_controllen = CONTROL_LEN;

	int ret = sendmsg(fd,&msg,0);
	if(ret == -1)
	{
		printf("sendmsg: errno = %d\n",errno);
	}

}
int recv_fd(int fd)
{
	struct  iovec iov[1];
	struct msghdr msg;
	char buf[0];

	iov[0].iov_base = buf;
	iov[0].iov_len = 1;
	msg.msg_name = NULL;
	msg.msg_namelen = 0;
	msg.msg_iov = iov;
	msg.msg_iovlen = 1;

	struct cmsghdr cm;
	msg.msg_control = &cm;
	msg.msg_controllen = CONTROL_LEN;


	int ret = recvmsg(fd,&msg,0);
//	printf("recvmsg: ret = %d\n",ret);
	if(ret == -1)
	printf("recvmsg ret == -1 .errno = %d\n",errno);
	int fd_to_read = *(int*)CMSG_DATA(&cm);
	return fd_to_read;
}

int main()
{
	int pipefd[2];
	int fd_to_pass = 0;
	int ret = socketpair(PF_UNIX,SOCK_DGRAM,0,pipefd);
	assert(ret!=-1);

	pid_t pid = fork();
	assert(pid>=0);

	if(pid == 0)
	{
		fd_to_pass = open("test.txt",O_RDWR,0666);
		send_fd(pipefd[1],fd_to_pass);
		close(fd_to_pass);
	}
	else 
	{
	sleep(3);
	fd_to_pass = recv_fd(pipefd[0]);
	char buf[1024];
	memset(buf,'\0',1024);
	ret = read(fd_to_pass,buf,1024);
	if(ret == -1)
	printf("errno = %d\n",errno);
	printf("i got fd %d and data %s\n",fd_to_pass,buf);
	close(fd_to_pass);
	}
	}

