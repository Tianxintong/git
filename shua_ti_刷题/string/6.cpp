#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<string> vec;
	for(int i =0;i<n;++i)
	{
		string tmp;
		cin>>tmp;
		sort(tmp.begin(),tmp.end());
//		cout<<tmp<<endl;
		vec.push_back(tmp);
	}
	int flag[50] =	{0};
	sort(vec.begin(),vec.end());
/*
	vector<string>::iterator it = vec.begin();
	while(it != vec.end())
	{
		cout<<*it<<"	";
		++it;
	}
*/
	int size = vec.size();
	int count = 1;
	for(int i = 1;i<size;++i)
	{
		if(vec[i] != vec[i-1])
		{
			++count;
		}
	}
	cout<<count<<endl;


	return 0;
}

/*
	vector<string> t;
	t.push_back(vec.front());

	int j = 0;
	
	for(j = 1;j<vec.size();++j)
	{
		int i =0;
		for(i = 0;i<t.size();++i)
		{
			if(vec[j] == t[i])
			break;
		}
		if(i == t.size())
			t.push_back((vec[j]));
	}
	cout<<t.size()<<endl;

	return 0;
}
*/
