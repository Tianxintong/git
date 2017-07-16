#include<iostream>

using namespace std;

void bit_set(unsigned char *p_data,unsigned char position,int flag)
{
	if(flag)
	{
		(*p_data)|=(1<<(position-1));
	}
	else
	{
		(*p_data) &= ~(1<<(position-1));
	}
}
/*
void RightLoopMove(char &pStr,unsigned short steps)
{
	int len = sizeof(pStr)-1;
	char *tm =(char *)malloc(len+1);
	strcpy(tm,pStr);
	int i = len -steps,j =0;
	for(;j<len;++j,i = (++i)%(len-1))
	pStr[j] = tm[i];
}*/
int main()
{
/*
	char ar[] = "abcdefhhi";
	RightLoopMove(ar,2);
	cout<<ar<<endl;
*/
	unsigned	char a = 'A';
	bit_set(&a,2,1);
	cout<<"a = "<<a<<endl;
	return 0;
}
