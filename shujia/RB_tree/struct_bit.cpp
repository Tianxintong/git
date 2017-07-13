#include<iostream>
#include<unistd.h>
using namespace std;

struct test
{
	int a:1;
	int b:2;
	int c:3;
};
int main()
{
	test t;
	t.a = 1;
	t.b = 3;
	t.c =7;
	cout<<t.a<<" ,"  <<t.b<<"  ,"<<t.c<<endl;

	for(char i = 0;i < 400;++i)
	{
	cout<<(int)i<<"   ";
//	sleep(1);
	}
	return 0;
}
