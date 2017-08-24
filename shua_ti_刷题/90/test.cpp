#include<iostream>
using namespace std;
bool  g_InvalidInput = true;

bool equal(double a,double b)
{
	if((a-b > -0.0000001) &&( a-b < 0.0000001))
	{
		return true;
	}
	return false;
}
double PowerUnsignedExponent(double base,unsigned int exponent)
{
	double result;
	if(exponent == 0)
	return 1;
	result = base;
	
	int n = (exponent>>1);
	while(n)
	{
		result *= result;
		n  = n>>1;
	}
	if( exponent & 1)
	result *= base;
	return result;
}
double power(double base,int exponent)
{
	if( equal(base,0.0) && exponent < 0)
	{
		g_InvalidInput = true;		
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)exponent;

	if( exponent < 0)
		absExponent = (unsigned int )(-exponent);
	
	double result = PowerUnsignedExponent(base,absExponent);

	if(exponent < 0)
	result = 1.0/result;

	return result;

}
int  main()
{
	double d;
	int exponent;
	cin>>d;
	cin>>exponent;
	cout<<power(d,exponent)<<endl;

	return 0;
}
