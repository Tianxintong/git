#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void RightLoopMove(char *pStr,unsigned short steps)
{
	int len = strlen(pStr);
	printf("strlen(pStr) = %d\n",len);
//	printf("sizeof(pStr) = %d\n",sizeof(pStr));//注意：sizeof计算的是char* 类型的占用内存多大,64位系统是8
	char *tm =(char *)malloc(len+1);
	strcpy(tm,pStr);
	printf("len = %d\n",len);
	int i = len -steps,j =0;
	for(;j<len;++j,i = (++i)%len)
	{
	//	printf("%d\n",i);
		pStr[j] = tm[i];
		
	}
	free(tm);
}
	//abcdefghi
void RightLoopMove_1(char *pStr,unsigned short steps)
{
	int str_len = strlen(pStr);//注意是strlen 而不是sizeof
	int step = steps % str_len;//防止移动的长度大于字符串的长度

	char * tmp = (char*)malloc(sizeof(char)*step);
	strncpy(tmp,pStr+str_len-step,step);
	memcpy(pStr+step,pStr,str_len-step);
	memcpy(pStr,tmp,step);
	free(tmp);


}
int main()
{
	char ar[] = "abcdefgkkkkkkkkhi";
	RightLoopMove(ar,2);
	printf("%s\n",ar);
	RightLoopMove_1(ar,2);
	printf("%s\n",ar);
	return 0;
}
