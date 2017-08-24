#include<iostream>
using namespace std;
unsigned int func(unsigned int v)
{
	v^=v>>16;
	v^=v>>8;
	v^=v>>4;
	v &= 0xf;
	return (0x6996 >> v)&1;
}
int main()
{
	int n =10;
	unsigned int t = 1<<n;
	int val = 0;
	cout<<t<<endl;
	for(int i =0;i< t;++i)
	{
		val += func(i);
	}
	cout<<"val = "<<val<<endl;
	return 0 ;
}
