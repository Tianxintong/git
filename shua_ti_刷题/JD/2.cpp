#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int left,right;
	cin>>left>>right;
	int i = left;
	int count = 0;
	for(;i<=right;++i)
	{

		if(i <= 10||i == 100||i==1000||i==10000||i==100000)
		continue;
		vector<int> vec;
		int tmp = i;
		int sum = 0;

		while(tmp)
		{
			vec.push_back(tmp%10);
			sum += tmp%10;
			tmp = tmp/10;
		}

		sort(vec.begin(),vec.end());
		tmp = sum/2;
		int j = 0;
		while(tmp != sum && sum > tmp && j<vec.size())
		{
			sum -= vec[j++];
		}
		if(tmp == sum)
		{
	cout<<i<<"	";
		++count;
		}
	}
	cout<<count<<endl;
	return 0;
}
