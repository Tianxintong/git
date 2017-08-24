#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


struct st_task
{
	uint16_t id;
	uint32_t value;
	uint64_t timeatsmp;
}
int main()
{
	st_task = {};
	uint64_t =  0x00010001;

}
/*

struct  Data
{
	char a;
	int b;
	int64_t  c;
	char d;
};

int main()
{
	Data a[2][10];
	cout<<a<<endl;
	cout<<&a[1][15]<<endl;
//	cout<<(a - &a[1][15])<<endl;
	cout<<sizeof(Data)<<endl;;
	cout<<15*sizeof(Data)<<endl;

return 0;
}
*/
