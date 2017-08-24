#include<iostream>
#include<stdio.h>
#include<unistd.h>

using namespace std;


int main()
{

	for(int i =0;i< 2;++i)
	{
		printf("-\n");
		fork();
	}
	return 0;
}

/*
class MyClass
{
public:
	MyClass(int i =0)
	{cout<<1;}
	MyClass(const MyClass &x)
	{cout<<2;}
	MyClass& operator=(const MyClass &x)
	{
		cout<<3;
		return *this;
	}
	~MyClass()
	{
		cout<<4;
	}
};
int main()
{
	MyClass obj1(1),obj2(2);
	MyClass obj3 = obj1;

	return 0;
}

*/
