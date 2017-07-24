#include<iostream>
#include<assert.h>
#include<stdlib.h>
#include<deque>
#include<string.h>
using namespace std;
#include"./bigint.h"
int main()
{
	char s1[] = "+1256738328939";
	char s2[] = "-32398389498";
	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);
	BigInt big1((u_char*)s1,len1);
	BigInt big2((u_char*)s2,len2);
	BigInt big3(0);
	cout<<"bt1 = ";
	big1.show();
	cout<<"bt2 = ";
	big2.show();
//	BigInt::Sub(big3,big1,big2);
//	cout<<(big1<big2)<<endl;
//	cout<<(big1>big2)<<endl;
//	BigInt::Mul(big3,big1,big2);
	cout<<"bt3 = bt1-bt2=";
	BigInt::Div(big3,big1,big2);
	big3.show();
}
