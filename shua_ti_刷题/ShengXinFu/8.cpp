#include<stdio.h>
#include<iostream>

using namespace std;
union uni
{
	struct
	{
		char *p1;
		int n2;
		char c;
	}s1;
	struct
	{
		int n3;
		char *p4;
	}s2;
};
int main()
{
	union uni u;
	cout<<sizeof(u)<<endl;
	cout<<sizeof(&u)<<endl;
	cout<<(int *) &u.s2.p4 - (int *) &u.s1.p1  <<endl;
	cout<<(char  *) &u.s2.n3 - (char *)&u.s1.p1  <<endl;
	return 0;
}
