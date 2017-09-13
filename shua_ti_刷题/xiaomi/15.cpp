#include<iostream>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i =0;i<= n/2;++i)
	{
		if( m - i <= n)
		cout<<m-i<<" "<<i<<endl;
	}
	return 0;
}
