#include<iostream>

#include<boost/smart_ptr.hpp>
//#include<boost/scoped_ptr.hpp>
//#include<boost/smart_ptr/scoped_ptr.hpp>
using namespace std;
using namespace boost;

class test
{
public:
	test(int d = 0 ):data(d)
	{}
	operator int()const
	{
		return data;
	}
private:
	int data;
};


int main()
{
//	int *a  = new int(20);
//	auto_ptr<int> pa(new int(10));
//	auto_ptr<int>pb(a);
//	pa = pb;

//	scoped_ptr<int> ps ( new int(13));
//	scoped_ptr<int> pd = ps;
/*
	test t;
	t=100;
	int value ;
	value = t;//强制转换
	cout<< "value = "<<value<<endl;
*/
	int *q = new int(99);
	shared_ptr<int> sp (q);
	shared_ptr<int> sp1 = sp;
	cout<<"sp.unique() = "<<sp.unique()<<endl;
	cout<<"sp.use_count() = "<<sp.use_count()<<endl;
return 0;
}
