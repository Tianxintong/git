#include<stdio.h>
#include<iostream>
using namespace  std;
int main()
{
	int a[5][2] = {0,1,2,3,4,5,6,7,8,9};
	int *p = a[1];
	int (*p2)[2] = &a[1];
	++p;
	++p2;
	printf("%d	",*p);
	printf("%d	",**p2);
	printf("%d	",p2[1][2]);
	return 0;
}
