#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
	int n;
	n = 8;
//	cin>>n;
	int height[n] = {2, 3, 5, 7 ,11, 13 ,17 ,19};
/*	for(int i = 0;i<n;++i)
	{
		cin>>height[i];
	}
*/
	int sub[n][n-2];
	for(int i =0;i<n;++i)
	memset(&sub[i],0,sizeof(int)*(n-2));
	int max = 0;
	int sum[n]={0};
	int tag = 0;
	for(int i = 0;i<n-2;++i)
	{
		for(int k = 0;k<i;++k)
		cout<<"	";
		for(int j = i+1;j<n;++j)
		{
			sub[i][j] = abs(height[i] - height[j]);
			cout<<sub[i][j]<<"	";
		}
		cout<<endl;cout<<endl;
	}


	return 0;
}
