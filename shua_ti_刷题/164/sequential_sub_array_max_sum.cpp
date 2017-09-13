#include<iostream>
#include<vector>
using namespace std;

void FindGreatestSumOfSubArray(int *a,int len)
{
	if(a == NULL || len <= 0)
	return;
		
	vector<int> vec;

	int cur_sum = a[0];
	int max_sum = a[0];
	
	vec.push_back(a[0]);
	for(int i =1;i<len;++i)
	{
		if(cur_sum > 0)
		{
			cur_sum += a[i];
			vec.push_back(a[i]);
		}
		else
		{
			cur_sum = a[i];
			vec.clear();
			vec.push_back(a[i]);
		}

		if(cur_sum >= max_sum)
		{
			max_sum = cur_sum;
		}
	}
	cout<<max_sum<<endl;

	//show the sub array which is greatest max sum.
	while(vec.back()  <= 0)
	vec.pop_back();
	vector<int>::iterator it = vec.begin();
	while( it != vec.end())
	{
		cout<<*it<<"	";
		++it;
	}
	cout<<endl;
}
int main()
{
	int a[] = {1,-2,3,10,-4,7,2,-5};
	int len = sizeof(a)/sizeof(a[0]);
	FindGreatestSumOfSubArray(a,len);
	return 0;
}
