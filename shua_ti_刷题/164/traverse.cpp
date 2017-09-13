#include<iostream>
using namespace std;
void MoreThanHalf(int *a,int len)
{
	if(a == NULL || len == 0)
	return;

	int key = a[0];
	int count = 1;
	for(int i = 1;i < len; ++i)
	{
		if(key == a[i])
		{
			++count;
		}
		else
		{
			if(count == 0)
			{
				key = a[i];
				count = 0;
			}
			else
			--count;
		}
	}
	cout<<key<<endl;
}

int main()
{
	int a[] = {1,2,3,2,2,2,5,4,2};
	int len = sizeof(a)/sizeof(a[0]);
	MoreThanHalf(a,	len);
	return 0;
}
