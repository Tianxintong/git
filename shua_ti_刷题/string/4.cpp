#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int x[n];
	int y[n];
	int j = 0;
	while(j<n)
	{
		cin>>x[j]>>y[j];
		++j;
	}
	int min_x=x[0],max_x=x[0],min_y=y[0],max_y = y[0];
	for(int i = 1;i<n;++i)
	{
		if(x[i] < min_x)
		min_x = x[i];
		if(x[i] > max_x)
		max_x = x[i];
		
		if(y[i] <min_y)
		min_y = y[i];
		if(y[i] > max_y)
		max_y = y[i];
	}
	int sum = (max_y - min_y)*(max_x - min_x);
	cout<<sum<<endl;
	return 0;
}
