#include<iostream>
using namespace std;
bool g_bInputInvalid = false;
bool CheckInvalidArray(int *numbers,int length)
{
	g_bInputInvalid = false;
	if(numbers == NULL ||length<=0)
	g_bInputInvalid = true;

	return g_bInputInvalid;
}
bool CheckMoreOneHalf(int *numbers,int length,int number)
{
	int times = 0;
	for(int i =0;i<length;++i)
	{
		if(numbers[i] == number)
		{
			++times;
		}
	}
	bool isMoreThanHalf = true;
	if(times*2 <= length)
	{
		isMoreThanHalf = false;
	}
	return isMoreThanHalf;
}


int MoreThanHalfNum(int length,int *numbers)
{
	if(CheckInvalidArray(numbers,length))
	return 0;

	int result = numbers[0];
	int times = 1;
	for(int i = 1;i<length;++i)
	{
		if(times == 0)
		{
			result = numbers[i];
			times = 1;
		}
		else if(numbers[i] == result)
		times++;
		else
		times--;
	}

	if(!CheckMoreOneHalf(numbers,length,result))
	result = 0;

	return result;
}
int main()
{
	int a[9] = {1,2,2,3,2,2,2,5,4};
	cout<<MoreThanHalfNum(9,a)<<endl;
	return 0;
}
