#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;

void PrintNumber(char *number)
{
	bool isBegining0 = true;
	int nLength = strlen(number);

	for(int i =0;i<nLength;++i)
	{
		if(isBegining0 && number[i] != '0')
		{
			isBegining0 = false;
		}
		if(!isBegining0)
		printf("%c",number[i]);
	}
	printf("\t");
}
void Print1ToMaxNDigitsRecursively(char *number,int lenngth,int index)
{
	if(index == lenngth -1)
	{
		PrintNumber(number);
		return;
	}
	for(int i = 0;i<10;++i)
	{
		number[index+1] = i+'0';
		Print1ToMaxNDigitsRecursively(number,lenngth,index+1);
	}
}
void Print1ToMaxNDigits(int n)
{
	if(n <= 0)
	return;

	char *number = new char[n+1];
	number[n] = '\0';

	for(int i = 0;i<10;++i)
	{
		number[0] = i +'0';
		Print1ToMaxNDigitsRecursively(number,n,0);
	}
	delete [] number;
}

int main()
{
	int n;
	cin>>n;
	Print1ToMaxNDigits(n);
	return 0;
}
