#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int adding = 1;
void carry_bit(char * number,int n)
{
	int i =1;
	while(i<n)
	{
		if(number[i] < '9')
		{
			number[i]++;
			break;
		}
		if( i == n-1 && number[i] == '9')
		{
			adding = 0;
			break;
		}
		number[i] = '0';
		++i;
	}
}
void output(char  *number,int n)
{
	int i = n-1;
	while(number[i] == '0')
	--i;
	while(i >= 0 )
	{
		cout<<number[i--];
	}
	cout<<"	";
}
void Print1ToNaxOfNDigits(int n)
{
	if( n <= 0)
	return;
	
	char *number = new  char[n+1];
	number[n] = '\0';
	memset(number,'0',n);

	int i =0,j =0;
	while(adding)
	{
		if(number[0] == '9')
		{
			number[i] = '0';
			carry_bit(number,n);
			if(adding)
			output(number,n);
			continue;
		}
		number[0]++;
		output(number,n);
	}
}
int main()
{
	int n;
	cin>>n;
	Print1ToNaxOfNDigits(n);
	return 0;
}
