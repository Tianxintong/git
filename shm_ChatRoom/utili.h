//#define _GNU_SOURCE
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<assert.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<poll.h>
#include <libgen.h>
#include<signal.h>
#include<sys/epoll.h>
#include<sys/wait.h>
#include<sys/mman.h>
#include<sys/stat.h>
#
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 9090

#define MAX_BUFFER_SIZE 256
