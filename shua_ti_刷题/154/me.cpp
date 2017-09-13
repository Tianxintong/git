#include<iostream>

using namespace std;
//输入一个字符串，求其全排列．比如:abc 全排列是: abc acb bac  bca cab cba
void Permutation(char *pStr,char *pBegin)
{
	if(*pBegin == '\0')
	cout<<pStr<<"	";
	else
	{
		for(char *pch = pBegin; *pch != '\0';++pch)
		{
			char temp = *pch;
			*pch = *pBegin;
			*pBegin = temp;

			Permutation(pStr,pBegin+1);
			
			temp = *pch;
			*pch = *pBegin;
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
