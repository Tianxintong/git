#include<iostream>
using namespace std;

class A
{
public:
	void print()
	{
		cout<<"A\n"<<endl;
	}
};
int main()
{
	A *pa = 0;
	pa->print();
	return 0;
}
/*
class Test
{
	int a;
public:
	Test():a()
	{
		cout<<"void"<<endl;
	}
	explicit Test(int i):a(i)
	{
		cout<<"int"<<endl;
	}
	Test(short s):a(s)
	{
		cout<<"short"<<endl;
	}
	Test& operator=(int n)
	{
		a = n;
		cout<<"operator="<<endl;
	}
};
int main()
{
	int n;
	Test a = n;
	return 0;
}
class A
{
public:
	virtual ~A(){}
};
class B
{
public:
	virtual ~B()
	{}
};
void test(int a,int b=7,char* p="*")
{

}
class C:public A,public B{};
int main()
{
	test(6,'a');
	C* pc = new C();
	A* pa = (A*) pc;
	B* pb = (B*)pc;
	cout<<pc<<endl;
	cout<<pa<<endl;
	cout<<pb<<endl;
	return 0;
}


int main()
{
	int count = 0;
	int x = 9999;
	while(x)
	{
		++count;
		x = x&(x-1);
		cout<<x<<"	:"<<count<<endl;
	}
	cout<<count<<endl;
	return 0;
}
int main()
{
	int n,m;
	cin>>n;
	cin>>m;
	int count = 0;
	for(int i =0;i<32;++i)
	{
		if((m&(1<<i)) !=(n&(1<<i)))
		++count;
	}
	cout<<count<<endl;
	return 0;
}


int main()
{
	int i;
	for(i = 10;i<32;++i)
	{
		if(i*i%10 == i%10 && i*i/10%10 == i/10)
		cout<<i<<endl;
	}
}
*/
