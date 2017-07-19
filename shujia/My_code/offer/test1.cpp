#include<iostream>

using namespace std;
bool search_1(int *a,int c,int r,int key)
{
	int x = c-1,y = r-1;
	int i = 0;
	while(i<c)
	{
		if(*(a+i) == key)
		return true;
		if(*(a+i)>key)
		{
			x = i;
			break;
		}
		++i;
	}
	i = 0;
	while(i<r)
	{
		if(*(a+c*i) == key)
		return true;
		if(*(a+c*i)>key)
		{
			y = i;
			break;
		}
		++i;
	}
	cout<<"x = "<<x<<"  :  "<<"y = "<<y<<endl;
	for(int i =0;i<=x;++i)
	{
		for(int j = 0;j<= y;++j)
		{
			if(*(a+i*c+r) == key)
			return true;
		}
	}
return false;
}
bool search(int a[][4],int key)
{
	int x = 4,y = 4;
	for(int i = 0;i<4;++i)
	{
		if(a[0][i]>=key)
		{
			x = i;
			break;
		}
	}
	for(int i = 0;i<4;++i)
	{
		if(a[i][0]>=key)
		{
			y = i;
			break;
		}
	}
	cout<<"x = "<<x<<"  :  "<<"y = "<<y<<endl;
	for(int i =0;i<=x;++i)
	{
		for(int j = 0;j<= y;++j)
		{
			if(a[i][j] == key)
			return true;
		}
	}
	return false;
}
int main()
{
	int a[4][4] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
//	cout<<search(a,99)<<endl;
	cout<<search_1((int *)a,4,4,99)<<endl;
	return 0;
}
