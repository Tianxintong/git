#include<unistd.h>
#include<time.h>
#include<stdlib.h>

#include<iostream>
using namespace std;
time_t t;
void  swap(int *a,int *b)
{
		int t = *a;
		*a = *b;
		*b = t;
}
int  partition(int a[],int len,int start,int end)
{
		if(start >= end || len <=0)
				return start;
		int i = start-1;
		int r = end;
		for(int j = start;j<end;++j)
		{
				if(a[j] <= a[r])
				{
						++i;
						if(j != i)
						{
							swap(a[i],a[j]);
						}
				}
		}
		swap(a[i+1],a[end]);
		return i+1;
}
void quickSort(int a[],int len,int start,int end)
{
		if(a != NULL && len >0 && start <end)
		{
				t = rand()%(end-start+1)+start;
				if(t != end);
				swap(&a[end],&a[t]);
				int q = partition(a,len,start,end);
				quickSort(a,len,start,q-1);
				quickSort(a,len,q+1,end);
		}
}
int main()
{
		srand((unsigned int)time(&t));
		int a[] = {9,87,65,4,2,3,45,6,0,1,33,7};
		int len = sizeof(a)/sizeof(int);
		quickSort(a,len,0,len-1);
		for(int i = 0;i<len;++i)
		{
				cout<<a[i]<<"  ";
		}
		cout<<endl;
		return 0;
}
