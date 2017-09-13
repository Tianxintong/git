#include<iostream>
using namespace std;

int main()
{
	int n,m;
	cin>>n;
	cin>>m;
	int a,b,c,d,x,y,z;
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	cin>>x;
	cin>>y;
	cin>>z;
	
	int t =x -  y*b/c - z*a/d;
	int t1 = y*m/c + z*n/d;
	int sum = 0;
	int p1,p2,p3;
	if(t > 0)
	{
		int w;
		p1 =( n/a > m/b ?m/b:n/a);
		sum  = p1 *x;
		if(n - p1*a >=d)
		sum += ( (n - p1*a)/d*z );
		if(m - p1*b >= c)
		sum +=( (m-p1*b)/c*y );
	}
	else
	{
		sum = t1;
		if(n%d >= a && m%c >=b)
		{
			sum+= (n%d/a >m%c/b ?m%c/b : n%d/a)*x;
		}
	}
	cout<<sum<<endl;

	return 0;
}
