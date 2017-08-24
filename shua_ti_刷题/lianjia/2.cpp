#include<iostream>
using namespace std;

int main()
{
	int h[10];
	int i,j;
	for(i = 0;i<10;++i)
	cin>>h[i];

	int tt;
	cin>>tt;
	
	int count = 0;

	for( i =0;i<10;++i)
	{
		if((tt+30)>=h[i])
		++count;
	}
	cout<<count<<endl;
	return 0;
}
