#include<iostream>
#include<stdlib.h>
#include<deque>
using namespace std;
#include"./bigint.h"
int main()
{
	BigInt big1(12345);
	BigInt big2(9239);
	BigInt big3(0);
	big1.show();
	big2.show();
//	BigInt::Add(big3,big,big1);
	cout<<(big1<big2)<<endl;
	cout<<(big1>big2)<<endl;
//	big3.show();
}
