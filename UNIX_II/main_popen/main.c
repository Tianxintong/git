#include"../utili.h"

int  main(int argc,char **argv)
{
	size_t n;
	char buff[MAXLEN],command[MAXLEN];
	FILE* fp;

	char *q = fgets(buff,MAXLEN,stdin);
	assert(q);

	n = strlen(buff);
	if(buff[n-1] == '\n')
	--n;

	snprintf(command,sizeof(command),"cat %s",buff);
	fp = popen(command,"r");

	while(fgets(buff,MAXLEN,fp)!=NULL)
	{
		fputs(buff,stdout);
	}
	pclose(fp);
	exit(0);
}
