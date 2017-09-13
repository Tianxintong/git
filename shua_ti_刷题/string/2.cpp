#include<iostream>

using namespace std;

int main()
{
	
	int a,b;
	cin>>a>>b;
	int c;
	cin>>c;
	int count = b/c - a/c;
	if(a<= 0 && b>0)
	++count;
	cout<<count<<endl;
	return 0;
}
