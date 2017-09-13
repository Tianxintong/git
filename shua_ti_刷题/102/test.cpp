#include<iostream>
using namespace std;
void output(int *pData,int len)
{
	for(int i = 0; i<len;++i)
	cout<<pData[i]<<"	";
	cout<<endl;
}
void ReoderOddEven(int *pData,unsigned int length)
{
	int left,right;
	left = 0;
	right = length - 1;
	int tmp;
	while(left<right)
	{
		while(pData[left]%2 && left < right)
		{
			++left;
		}
		while(pData[right]%2 == 0 && right > left)
		{
			--right;
		}
		if(left != right)
		{
			tmp = pData[left];
			pData[left] = pData[right];
			pData[right] = tmp;
		}
	}
}
int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9};
	int len = sizeof(a)/sizeof(a[0]);
	ReoderOddEven(a,len);
	output(a,len);
	return 0;
}
