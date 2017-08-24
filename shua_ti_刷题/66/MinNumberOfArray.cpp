#include<iostream>
#include<vector>
using namespace std;

int MinInOrder(vector<int> rotateArray)
{
	int result = rotateArray[0];
	int index1 = 0;
	int index2 = rotateArray.size()-1;
	for(int i=index1+1;i<index2;++i)
	{
		if(result < rotateArray[i])
		{
			result = rotateArray[i];
		}
	}
	return result;
}
int minNumberInRotateArray(vector<int> rotateArray)//the answer of <<剑指offer>> : test run time:28 ms
{
	if(rotateArray.size() == 0 )
	return 0;
	int length = rotateArray.size();
	int index1 = 0;
	int index2 = length-1;
	int indexMid = index1;
	while(rotateArray[index1] >= rotateArray[index2])
	{
		if(index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
		indexMid = (index2+index1)/2;
		if(rotateArray[index1] == rotateArray[index2] && rotateArray[indexMid] == rotateArray[index1])
		{
			return MinInOrder(rotateArray);
		}
		if(rotateArray[indexMid] >= rotateArray[index1])
			index1 = indexMid;
		else if(rotateArray[indexMid] <= rotateArray[index2])
			index2 = indexMid;
	}
	return rotateArray[indexMid];
}

/*
//code of myself    the code test time: 26 ms
int minNumberInRotateArray(vector<int> rotateArray)
{
	if(rotateArray.size() == 0)
		return 0;
	if(rotateArray.size() == 1)
		return rotateArray[0];
	int len = rotateArray.size();
	int i = 0;
	int min = rotateArray[0];
	int tmp;
	for(;i<len;++i)
	{
		tmp = rotateArray[i];
		if(tmp >rotateArray[i+1])
		{
			if(min > rotateArray[i+1])
			min = rotateArray[i+1];
			cout<<" circlu times = "<<i<<endl;
			return min;
		}
	}
	return min;
}
*/
int main()
{
	vector<int> vec;
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(1);
	vec.push_back(2);
	cout<<"min = "<<minNumberInRotateArray(vec)<<endl;
		return 0;
}
