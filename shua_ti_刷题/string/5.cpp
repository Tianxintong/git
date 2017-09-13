#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin>>n;

	vector<int> vec;
	while(n)
	{
		vec.push_back(n%10);
//		cout<<n%10<<"	";
		n = n/10;
	}
	int cur = 0;
	int len = vec.size();
	bool is = false;
	for(cur = 0;cur < len-1;++cur)
	{
		int  left = 1,right = 1;
		for(int i = 0;i<= cur;++i)
		{
			left *= vec[i];
		}
		for(int j = cur+1;j<len;++j)
		{
			right *= vec[j];
		}
		if(right == left)
		{
			is = true;
			break;
		}
		left = right = 1;
	}
	if(is)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	return 0;
}
