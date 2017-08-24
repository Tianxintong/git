#include<iostream>
#include<time.h>
#include<unistd.h>
using namespace std;

class Matric
{
		public:
				Matric()
				{
						a =1;
						b=1;
						c =1;
						d =0;
				}
				Matric operator*(Matric m)
				{
						Matric t;
						t.a = a * m.a  +  b * m.c;
						t.b = a * m.b  +  b * m.d;
						t.c = c * m.a  +  d * m.c;
						t.b = c * m.b  +  d * m.d;
						return t;
				}	
				int a;
				int b;
				int c;
				int d;

};
Matric m;
Matric fun_m(unsigned int n)
{
		if(n == 2||n == 1||n==0)
		{
				return m;
		}
		if(n %2)
				return fun_m((n-1)/2)*fun_m((n-1)/2)*m;
		else
				return fun_m(n/2)*fun_m(n/2);
};
long long fun(unsigned int n)
{
		if(n == 1)
				return 2;
		if(n == 0)
				return 1;
		if(n %2)
				return fun((n-1)/2)*fun((n-1)/2)*2;
		else
				return fun(n/2)*fun(n/2);
}
long long fun1(unsigned int n  )
{
		if( n ==0)
				return 1;
		if(n== 1)
				return 2;
		long long  ret = 1;
		for(int i =0;i<n;++i)
				ret *=2;

		return ret;

}
int main()
{		for(int i =1;i<=20;++i)
		{
				Matric t = fun_m(i);
				cout<<"i ="<<i<<"  :  "<<t.a<<endl;

		}


		/*
		   time_t t;
		   time(&t);
		   cout<<t<<endl;
		   cout<<fun(1000000000000000)<<endl;;
		   time(&t);
		   cout<<t<<endl;
		   cout<<fun1(1000000000000000)<<endl;
		   sleep(2);
		   time(&t);
		   cout<<t<<endl;
		 */
		return 0;
}
