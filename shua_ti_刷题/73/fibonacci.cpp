#include<iostream>
using namespace std;

long long Fibonacci_for(unsigned int n)
{
	if(n == 1)
	return 1;
	if(n <=0)
	return 0;
	long long  f1,f2,f3;
	
	f1 = 0;
	f2 = 1;

	for(unsigned int i = 2;i<= n;++i)
	{
		f3 = f1+f2;
		f1 = f2;
		f2 = f3;
	}
	return f3;
}
long long Fibonacci(unsigned int n)
{
	if(n<=0)
	return 0;
	if(n == 1)
	return 1;
	return Fibonacci(n-1)+Fibonacci(n-2);
}
int main()
{
	cout<<Fibonacci(100)<<endl;
	return 0;
}
