#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int x;
	vector<int> v;
	int n;

	while(cin>>x)
	{
		v.push_back(x);
	}
	n = v.back();
	v.pop_back();

	sort(v.begin(),v.end());

	for(int i =0;i<n;++i)
	{
		cout<<v.at(i);
		if(i<n-1)
		{
			cout<<' ';
		}
		else
		cout<<endl;
	}

	return 0;
}
