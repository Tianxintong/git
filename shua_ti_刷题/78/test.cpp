/*
   输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 */
#include<stdlib.h>
#include<iostream>
using namespace std;
int NumberOf1_2(int n)
{
	int count = 0;
	while(n)
	{
		++count;
		n = (n-1)&n;
	}
	return count;
}
int NumberOf1(int n)
{
		if( n == 0)
				return 0;
		int s = n;
		long int  res = 1;
		int count = 0;
		for(int i = 0;i<32;++i)
		{
			if( s & res)
			++count;
			res = res <<1;
		}
		return count;
}
int main()
{
		int n;
		cin>>n;
		cout<<NumberOf1(n)<<endl;
}
