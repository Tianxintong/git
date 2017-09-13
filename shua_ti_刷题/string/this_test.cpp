#include<iostream>
using namespace std;

class A
{
public:
	void print()
	{
		cout<<"A"<<endl;
	}
	int i ;
	int j;
};
int main()
{
	A* pa = NULL;
	pa->print();
//	pa->i = 1;
	cout<<"pa = "<<pa<<endl;
	cout<<"&pa->i = "<<&pa->i<<"	"<<"&pa->j = "<<&pa->j<<endl;
	return 0;
}
/*
class B
{
public:
	int a;
	int b;
};
int main()
{
	B* p = NULL;
	int offset = (&(p->b) - &(p->a));
	cout<<offset<<endl;
	return 0;
}
*/
