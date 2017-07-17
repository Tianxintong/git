#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char acX[] = "abcdefgh";
	char acY[] = {'a','b','c','d','e','f','g','h'};
	int a;
	int b,c;
	char str[8] = {'a','b','c','d','e','f','g','h'};
	cout<<sizeof(acX)<<endl;
	cout<<sizeof(acY)<<endl;
	cout<<"strlen(acX)= "<<strlen(acX)<<endl;
	cout<<"strlen(acY)= "<<strlen(acY)<<endl;
	cout<<"strlen(str)= "<<strlen(str)<<endl;
return 0;
}
/*
int main()
{
	unsigned char a = 200;
	unsigned char b = 100;
	char c ;
	c = a+b;
	cout<<(int)c<<endl;
}


*/
