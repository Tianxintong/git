#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int i =0;
	int a[10];
	for(i = 0;i<10;++i)
	cin>>a[i];
	sort(a,a+9);
	for(i = 0;i<10;++i)
	cout<<a[i]<<"	";
	cout<<endl;
	return 0;
}
