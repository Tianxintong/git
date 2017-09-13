#include<iostream>
#include<vector>
using namespace std;

vector<string> Permutation(string str,int pos,vector<string> &vec)
{
	if(pos>= str.length())
	{
		vec.push_back(str);
		return vec;
	}
	else
	{
		for(int i = 0;i<str.length();++i)
		{
			char t = str[i];
			str[i] = str[pos];
			str[pos] = t;
			
			Permutation(str,pos+1,vec);

			t = str[i];
			str[i] = str[pos];
			str[pos] = t;
		}
	}
	
}
vector<string> Permutation(string str)
{
	vector<string> vec;
	if(str.length() == 0)
	return vec;

	return Permutation(str,0,vec);
}
int main()
{
	string str("abcd");
	vector<string> vec = Permutation(str);

	for(int i = 0;i<vec.size();++i)
	{
		cout<<vec[i]<<"	";
	}
	cout<<endl;
	return 0;
}	
