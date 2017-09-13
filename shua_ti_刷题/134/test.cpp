#include<iostream>
#include<stack>
#include<vector>
using namespace std;
 bool IsPopOrder(vector<int> pushV,vector<int> popV) 
{
	        stack<int> tmp;
			if(pushV.size() == 0 ||popV.size() == 0)
			return false;

			tmp.push(pushV[0]);
			int i = 1;
			vector<int>::iterator itpush = pushV.begin();
			++itpush;
			vector<int>::iterator itpop = popV.begin();
			while(!tmp.empty())
			{
				if(tmp.top() == *itpop)
				{
					tmp.pop();
					++itpop;
					if(itpop == popV.end() && !tmp.empty())
					return false;
				}
				else
				{
					if(itpush != pushV.end())
					{
						tmp.push(*itpush);
						++itpush;
					}
					else
					return false;
				}
			}
			if(itpop == popV.end())
			return true;
			else
			return false;
}
int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	vector<int> v2;
	v2.push_back(4);
	v2.push_back(3);
	v2.push_back(5);
	v2.push_back(1);
	v2.push_back(2);

	cout<<IsPopOrder(v1,v2)<<endl;
	return 0;
}
