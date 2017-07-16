#include<iostream>
using namespace std;
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"./rb_tree.h"
int main()
{
	RBTree rbt;
	InitRBTree(rbt);
	int ar[] = {100,70,80,50,40,75,73,72,74};
	int n = sizeof(ar)/sizeof(int);
	for(int i = 0;i<n;++i)
	Insert(rbt,ar[i]);
	sortPrint(rbt);
	return 0;
}
