#include<iostream>
using namespace std;

class A
{
public:
	virtual void f()
	{
		cout<<"A::f()"<<endl;
	}
	virtual void g()
	{
		cout<<"A::g()"<<endl;
	}
	void  k()
	{
		cout<<"A::k()"<<endl;
	}
private:
	int a;
};
class B:public A
{
public:
	void g()
	{
		cout<<"B::g()"<<endl;
	}
	void k()
	{
		cout<<"B::k()"<<endl;
	}
private:
	int b;
};

int main()
{
	B b;
	A *ap = &b;
	ap->g();
	ap->k();
	B* bp = &b;
	bp->f();
	return 0;
}
