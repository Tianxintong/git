#include<iostream>
using namespace std;

void NumberOf1Between1AndN(int n)
{
	if(n <= 0)
	return;

	int count = 0;
	if(n < 19)
	{
		for(int i = 1;i <= n;++i)
		{
			int tmp = i;
			while(tmp)
			{
				if(tmp%10 == 1)
				++count;
				tmp /= 10;
			}
		}
	}
	else
	{
		count = 12;
		for(int i = 21;i <= n;i = i+10)
		{
			++count;
		}
	}
	cout<<count<<endl;
}
int main()
{
	int n;
	cin>>n;
	NumberOf1Between1AndN(n);
	return 0;
}
