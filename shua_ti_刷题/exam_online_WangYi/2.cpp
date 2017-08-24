#include<iostream>
using namespace std;

int main()
{
	long long int x,f,d,p;
	cin>>x;
	cin>>f;
	cin>>d;
	cin>>p;
	if(p+x <=0 || x<0||f<0||d<0||p<0)
	{
		cout<<0<<endl;
		return 0;
	}
	long long days = 0;
	if(d/x<f)
		days = d/x;
	else
	{
		days = (d+f*p)/(p+x) ;
	}
	cout<<days<<endl;
	return 0;
}
