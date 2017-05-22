#include<unistd.h>
#include<stdio.h>
#include<errno.h>
//extern static int  errno;
int main(int argc,char **argv)
{
	int oc;//选项字符
	char * b_opt_arg;//选项字符串

	while((oc = getopt(argc,argv,"ngl:"))!= -1)
	{
		switch(oc)
		{
			case 'n':
			printf("this is a test of getopt fun\n");
			break;
			case 'g':
			printf("getopt function parse argc.!!\n");
			break;
			case 'l':
			{
				FILE *fp = fopen(optarg,"w");
				if(fp == NULL)
				{		
			//		printf("errno = %d\n",errno);
					printf("fopen fail\n");
					break;
				}
				fprintf(fp,"hello getopt.\n");
			}
		}
	}
	return 0;
}
