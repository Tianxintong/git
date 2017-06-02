#include"./shared_ptr.h"

#include<iostream>
using namespace std;

int main()
{
	int *q = new int(10);
	shared_ptr<int> sp(q);
	return 0;
}
