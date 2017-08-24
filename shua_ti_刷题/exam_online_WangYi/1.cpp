#include<deque>
#include<iostream>
using namespace  std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	deque<int> dq;
	for(int i=0;i<n;++i)
		cin>>a[i];
	for(int i = 0;i<n;++i)
	{
		if(i%2)
		dq.push_back(a[i]);
		else
		dq.push_front(a[i]);
	}
	deque<int>::iterator it ;
	if(n%2 == 0)
	{
		it = dq.end();
		--it;
		while(it!=dq.begin())
		{
			cout<<*it<<" ";
			--it;
		}
		cout<<*it;
	}
	else
	{
		it = dq.begin();
		deque<int>::iterator it1 = dq.end();
		--it1;
		while(it != it1)
		{
			cout<<*it<<" ";
			++it;
		}
		cout<<*it;
	}

	return 0;
}
/*
int main()
{
	long int  n;
	cin>>n;
	int a[n];
	int b[n];
	for(long int i =0;i<n;++i)
	{
		cin>>a[i];
	}
	for(long int i =0;i<n;++i)
	{
		b[i] = a[i];

		for(long int left = 0,right = i;left<right;++left,--right)
		{
			long int tm = b[left];
			b[left] = b[right];
			b[right] = tm;
		}
	}
	for(long int i = 0;i<n;++i)
	{
		cout<<b[i];
		if(i != (n-1))
		cout<<" ";
	}

	return 0;
}

*/
