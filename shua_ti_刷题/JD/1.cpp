#include<math.h>
#include<iostream>
using namespace std;

int main()
{	
	long long s;
	cin>>s;
	long long i  =0 ;
	long long ret = sqrt(s*2);
	i = ret*(ret+1)/2;
	if(s > i)
	ret = ret +1;
	cout<<ret<<endl;
	return 0;
}
