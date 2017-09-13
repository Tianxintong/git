#include<iostream>

//给出n(n<32767)个数，求任意的两个数字二进制表示位数不同的数量之和
using namespace std;
static int count = 0;
int main()
{
	int n;
	cin>>n;

	int a[n];
	for(int i =0;i<n;++i)
		cin>>a[i];
	for(int i = 0;i<n;++i)
	{
		for(int j = i+1;j<n;++j)
		{
			int tmp = a[i]&a[j];
			while(tmp)
			{
				tmp = tmp &(tmp - 1);
				++count;
			}
		}
	}
	cout<<"result = "<<count<<endl;
	return  0;
}

