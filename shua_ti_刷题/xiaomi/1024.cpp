#include<iostream>
using namespace std;

int main()
{
	long long int sum = 1;
	int i = 0;
	for(i = 2;i<1025;++i)
	{
		sum *=i;
	}
	cout<<sum<<endl;
	return 0;
}
