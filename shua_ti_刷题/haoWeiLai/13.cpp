#include<iostream>

using namespace std;

int main()
{
	string str;
	cin>>str;
	string result;

	string tmp;

	size_t len = str.length();
	int i = 0;
	while(i<len)
	{
		while(i<len && str[i]>='0' &&str[i] <='9')
		{
			tmp += str[i];
			++i;
		}
		if(result.length() < tmp.length())
		{
			result = tmp;
		}
			tmp.clear();
	
		++i;
	
	}
	cout<<result<<endl;
	return 0;
}
