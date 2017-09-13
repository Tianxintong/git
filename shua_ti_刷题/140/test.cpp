#include<iostream>
#include<vector>
using namespace std;
bool VerifySquenceOfBST(vector<int> sequence)
{
	if(sequence.size() == 0)
	return false;
	if(sequence.size() == 1)
	return true;
	
	int root = sequence[sequence.size()-1];
	vector<int> left;
	vector<int> right;
	
	vector<int>::iterator it = sequence.begin();
	while(it != sequence.end())
	{
		while(*it < root && it != sequence.end())
		{
			left.push_back(*it);
			++it;
		}
		while(*it > root && it != sequence.end())
		{
			right.push_back(*it);
			++it;
		}
		if((++it) != sequence.end())
		return false;
		if(left.size()== 0)
		{
			if(right.size() == 0)
			return true;
			else
			return VerifySquenceOfBST(right);
		}
		else
		{
			if(VerifySquenceOfBST(left))
			{
				if(right.size() != 0)
				return VerifySquenceOfBST(right);
				else
				return true;
			}
		}
		}
}
int main()
{
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(7);
	vec.push_back(6);
	vec.push_back(9);
	
	vec.push_back(11);
	vec.push_back(10);
	vec.push_back(8);  


	cout<<VerifySquenceOfBST(vec)<<endl;
	return 0;
}
