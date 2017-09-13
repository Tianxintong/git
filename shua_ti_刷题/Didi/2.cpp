#include<iostream>
using namespace std;

int Min(int number1,int number2,int number3)
{
	int min = (number1<number2)?number1:number2;
	min = (number3<min)?number3:min;
	return min;
}
int GetUglyNumber(int index)
{
	if(index <= 0)
	return 0;

	int *pUglyNumber = new int[index];
	pUglyNumber[0] = 1;
	int nextUglyIndex = 1;

	int *pMultiply2 = pUglyNumber;
	int *pMultiply3 = pUglyNumber;
	int *pMultiply5 = pUglyNumber;

	while(nextUglyIndex<index)
	{
		int min = Min(*pMultiply2*2,*pMultiply3*3,*pMultiply5*5);
		pUglyNumber[nextUglyIndex] = min;

		while(*pMultiply2*2 <= pUglyNumber[nextUglyIndex])
		++pMultiply2;

		while(*pMultiply3*3 <= pUglyNumber[nextUglyIndex])
		++pMultiply3;

		while(*pMultiply5*5 <= pUglyNumber[nextUglyIndex])
		++pMultiply5;

		++nextUglyIndex;
	}

	int ugly = pUglyNumber[nextUglyIndex-1];
	delete []pUglyNumber;
	return ugly;
}
int main()
{
	int n;
	cin>>n;
	cout<<GetUglyNumber(n)<<endl;
	return 0;
}
