#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(string str,int pos,vector<string> &vec)
{
	int len = str.length();
	
	

	for(int i = pos+1;i<len;++i)
	{
		string tmp(str);
		char t;
		t = tmp[i];
		tmp[i] = tmp[pos];
		tmp[pos] = t;
		vec.push_back(tmp);
//		cout<<tmp<<endl;
		
		print(tmp,pos+1,vec);
		
		t = tmp[i];
		tmp[i] = tmp[pos];
		tmp[pos] = t;
		vec.push_back(tmp);

		print(tmp,pos+1,vec);
	}
}
vector<string> Permutation(string str)
{
	vector<string> vec;

	if(str.length()==0)
	return vec;
	
	vec.push_back(str);
	string t = str;
	sort(str.begin(),str.end());
//	if(t == str)
//	return vec;
//	cout<<str<<endl;
	print(str,1,vec);

	print(str,0,vec);
	
	sort(vec.begin(),vec.end());
	return vec;
}
int main()
{
	string str("ab");
	vector<string> tmp = Permutation(str);
	vector<string>::iterator it = tmp.begin();

//cout<<"----------------------------------------------"<<endl;
	while(it != tmp.end())
	{
		cout<<*it<<endl;
		++it;
	}
	return 0;
}
