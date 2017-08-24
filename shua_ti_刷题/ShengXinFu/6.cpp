#include<stdio.h>
#include<iostream>
using namespace std;

struct Foo
{
	Foo(const char *name,int *p):m_name(name),m_p(p)
	{
		printf("%s : %d ",name,++*p);
		cout<<endl;
	}
	~Foo()
	{
		printf("%s : %d ",m_name,--*m_p);
		cout<<endl;
	}
	const char * m_name;
	int *m_p;
};
void fun(int *p)
{
	Foo("a",p);
	new Foo("b",p);
}
int main()
{
	int a = 1;
	fun(&a);
	printf("%d\n",a);

	return 0;
}
