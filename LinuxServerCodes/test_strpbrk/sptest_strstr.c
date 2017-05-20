   #include <unistd.h>
#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
		#include<stdlib.h>

int main()
{
	int cfg_fd = open("config.xml",O_RDONLY);
	if(cfg_fd<0)
	printf("open errno.\n");
	struct stat ret_stat;
	if(fstat(cfg_fd,&ret_stat)<0)
	printf("fstat fail.\n");
	char *buf = (char*)malloc(sizeof(char)*(ret_stat.st_size+1));
	memset(buf,'\0',ret_stat.st_size+1);
	ssize_t read_sz = read(cfg_fd,buf,ret_stat.st_size);
	if(read_sz < 0)
	{
		printf("read file to buf  fail\n");
		return 1;
	}
	int opentag = 0;
	char* tmp = buf;
	char *tmp2 =NULL;
	char* tmp3 = NULL;
	char* tmp4 = NULL;
	while(tmp2 = strpbrk(tmp,"\n"))
	{
		*tmp2++ = '\0';
		if(strstr(tmp,"<logical_host>"))
		{
			if( opentag)
			{
				printf("logical_host fail\n");
				return 1;
			}
			opentag = 1;
			printf("<logical_host>\n");
			printf("tmp = %s\n",tmp);
		}
		else if( strstr(tmp,"</logical_host>"))
		{
			if(!opentag)
			{
				return 1;
				printf("%s\n",tmp);
			}
			opentag = 0;
			printf("</logical_host>\n");
			printf("/tmp = %s\n",tmp);
		}
		else if( tmp3 = strstr(tmp,"<name>") )
		{
			tmp4 = strstr(tmp3+6,"</name>" );
			if(!tmp4)
			{
				printf("find name fail\n");
				return 1;
			}
			*tmp4 = '\0';
			printf("%s\n",tmp3+6);
		}
		tmp = tmp2;
	}
}
