#include<iostream>
#include<stdlib.h>
#include<deque>
#include<string.h>
using namespace std;
#include"./bigint.h"
int main()
{
	char s1[] = "+123456678943229";
	char s2[] = "-98765443312456789";
	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);
	BigInt big1((u_char*)s1,len1);
	BigInt big2((u_char*)s2,len2);
	BigInt big3(0);
	big1.show();
	big2.show();
	BigInt::Add(big3,big1,big2);
//	cout<<(big1<big2)<<endl;
//	cout<<(big1>big2)<<endl;
	big3.show();
}
