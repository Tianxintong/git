#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	int m = 0;
	while(m<n)
	{
		cin>>a[m++];
	}
	
	int count = 0;
	for(int i = 0;i<n;++i)
	{
		for(int j = i+1;j<n;++j)
		{
			for(int k = j+1;k<n;++k)
			{
				if((a[k] + a[i] >a[j])&&(a[i] + a[j] >a[k])&&(a[j] +a[k]>a[i]))
				++count;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}
