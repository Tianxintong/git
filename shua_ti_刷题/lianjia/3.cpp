#include<iostream>
#include <algorithm>   
using namespace std;

int main()
{
	int n;
	cin>>n;
	int id[n];
	int i,j;
	for(i =0;i<n ;++i)
	{
		cin>>id[i];
	}
	sort(id,id+n);

	int tmp[n] = {0};
	int front = id[0];
	tmp[0] = id[0];
	j = 1;

	for(i = 1;i<n;++i)
	{
		if(front == id[i])
		continue;
		tmp[j++] = id[i];
		front = id[i];
	}
	cout<<j<<endl;
	for(i = 0;i<j;++i)
	cout<<tmp[i]<<" ";
	cout<<endl;
return 0;
}
