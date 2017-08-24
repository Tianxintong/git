#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

/*请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。*/

void replaceSpace(char *string,int length)
{
	if(string == NULL ||length <0)
	{
		return;
	}
	
	int originalLen = 0;
	int i = 0;
	int space = 0;
	while(string[i] != '\0' && i<length)
	{
		++originalLen;
		if(string[i] == ' ')
		{
			++space;
		}
		++i;
	}
	
	int indexOfOriginal = originalLen;
	int indexOfNew = originalLen + 2*space;
	while(indexOfOriginal >=0 && indexOfOriginal < indexOfNew)
	{
		if(string[indexOfOriginal] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else
		{
			string[indexOfNew--] = string[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}
/*
//this version is code of book .the right answer.
void replaceSpace(char string[],int length)
{
	if(string == NULL||length <= 0)
	{
		return;
	}
	int originalLen = 0;
	int numberOfBlack = 0;
	int i = 0;
	while(string[i] != '\0')
	{
		++originalLen;
		if(string[i] == ' ')
			 ++numberOfBlack;
		++i;
	}
	int newLength = originalLen + numberOfBlack*2;
	if(newLength > length)
	return;
	int indexOfOriginal = originalLen;
	int indexOfNew = newLength;
	while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if(string[indexOfOriginal] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else
		{
			string[indexOfNew--] = string[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}
*/
/*
//this version is stack overflow in NieKe.com,but is right when i test,maybeit has some loophole I not found so i rewrite next.
void  replaceSpace(char *string,int len)
{
	if(string == NULL||len <1)
		return ;
	int i =0;
	int space = 0;
	int originalLen = 0;
	while(string[i] != '\0' && i < len)
	{
		if(string[i] == ' ')
			 ++space;
		++i;
		++originalLen;
	}
	i = originalLen;
	int j = originalLen + space*2 - 1;
	string[j+1] = '\0';
	while(space && i >0 && j>i)
	{
		if(string[i] == ' ')
		{
			string[j--] = '0';
			string[j--] = '2';
			string[j--] = '%';
			--space;
			--i;
		}
		else
		string[j--] = string[i--];
	}
	while(space--)
	{
		string[j--] = '0';
		string[j--] = '2';
		string[j--] = '%';
	}
	
//	while(i >= 0)
//	{
//		string[j--] = string[i--];
//	}
	
}

*/
int main()
{
	char string[1024] = "   We arehappy   ";
	int length = strlen(string);
	char *tmp = NULL;
	replaceSpace(string,length);
	cout<<string<<endl;
	return 0;
}
