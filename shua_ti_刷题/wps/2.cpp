#include<iostream>
using namespace std;
class A
{};
void f(const A **p){}
void g(const A *const *p){}
void k(const A *&p){}
int main()
{
	const A*ca = new A();
	A* a = new A();
	A**p = &a;
	k(ca);
	f(p);
	g(p);
	return 0;
}
