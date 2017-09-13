#include<iostream>
#include<stdio.h>
using namespace std;


void Permutation(char *pStr,char *pBegin)
{
	if( *pBegin == '\0')
	{
		printf("%s	",pStr);
	}
	else
	{
		for(char *ch = pBegin;*ch != '\0';++ch)
		{
			char temp = *ch;
			*ch = *pBegin;
			*pBegin = temp;

			Permutation(pStr,pBegin+1);
			temp = *ch;
			*ch = *pBegin;
			*pBegin = temp;
		}
	}
}

void Permutation(char *pStr)
{
	if(pStr == NULL)
	return;

	Permutation(pStr,pStr);
}
int main()
{
	char a[] = "abcd";
	Permutation(a);
	return 0;
}
