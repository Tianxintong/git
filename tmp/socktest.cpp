#include<iostream>
#include <sys/types.h>          /* See NOTES */
 #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
#include<string.h>
using namespace std;

int main()
{
	struct sockaddr_in my_addr;
	memset(&my_addr,0,sizeof(struct sockaddr_in));
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(8888);
	my_addr.sin_addr.s_addr = inet_addr("191.168.1.167");

	int sock =socket(AF_INET,SOCK_DGRAM,0);
	int ret = bind(sock,&my_addr,sizeof(struct sockaddr_in));
	
	char buffer[] = "test UDP";
	ret = sendto(sock,buffer,sizeof(buffer),0);
	return 0;

}
