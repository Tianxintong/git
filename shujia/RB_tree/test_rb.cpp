//#include<stdio.h>
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"./RB_tree.h"
int main()
{	
	RBTree brt;
	InitRBTree(brt);
	int ar[] = {100,70,80,50,40,75,73,72,74};
	int n =sizeof(ar)/sizeof(int);
	for(int i =0;i<n;++i)
	{
		Insert(brt,ar[i]);
	}
	show_RBTree(brt);
	cout<<endl;
	Remove(brt,72);
	show_RBTree(brt);
	cout<<endl;
	return 0;
}
