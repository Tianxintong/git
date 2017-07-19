#include<iostream>
#include<list>
#include<algorithm>
void show(int v)
{
	std::cout<<v<< "  ";
}
const int LIM = 10;
int main()
{
	using namespace std;
	int ar[LIM] = {4,5,4,2,2,3,4,8,1,4};
	list<int> la(ar,ar+LIM);
	list<int> lb(la);
	cout<<"original list contents:\n";
	for_each(la.begin(),la.end(),show);
	cout<<endl;
	la.remove(4);
	cout<<"After using the remove() method:\n";
	cout<<"la:"<<endl;
	for_each(la.begin(),la.end(),show);
	cout<<endl;
	list<int>::iterator last;
	last = remove(lb.begin(),lb.end(),4);
	cout<<"After using remove() function:"<<endl;
	cout<<"lb:"<<endl;
	for_each(lb.begin(),lb.end(),show);
}
