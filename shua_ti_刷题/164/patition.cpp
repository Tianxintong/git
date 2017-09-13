#include<iostream>

using namespace std;
void swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int *a,int len,int start,int end)
{
	if(start >= end || a == NULL)
	return 0;

	int small = start - 1;
	int index = end - 1;

	for(index = start;index < end;++index)
	{
		if(a[index] < a[end])
		{
			++small;
			if(index != small)
			swap(&a[index], &a[small]);
		}
	}
	++small;
	swap(&a[small],&a[end]);
	return small;
}
void partition(int *a,int len)
{
	if(a == NULL)
	return;

	int mid = len>>1;
	
	int start = 0;
	int end = len - 1;
	int index = partition(a,len,start,end);

	while(index != mid)
	{
		if(index > mid)
		{
			end = index - 1;
			index = partition(a,len,start,end);
		}
		else
		{
			start = index + 1;
			index = partition(a,len,start,end);
		}
	}

	int result = a[mid];
// check result if is more than half
	//..
	cout<<"result = "<<result<<endl;

}
int main()
{
	int a[] = {1,2,3,2,2,2,5,4,2};
	partition(a,sizeof(a)/sizeof(a[0]));
	return 0;
}
