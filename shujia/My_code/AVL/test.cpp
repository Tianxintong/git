#include<iostream>
using namespace std;

#include"./AVL.h"

int main()
{
	AVLTree<int> avl;
	int ar[11] = {16,3,7,11,8,20,9,26,18,14,15};
	for(int i=0;i<11;i++)
	avl.Insert(ar[i]);
	avl.sortPrint();
	cout<<endl;
	avl.remove(16);
	avl.sortPrint();
	cout<<endl;
///*
	avl.remove(7);
	avl.sortPrint();
	cout<<endl;
	avl.remove(26);
	avl.sortPrint();
	cout<<endl;
	avl.remove(8);
	avl.sortPrint();
	cout<<endl;
	avl.remove(15);
	avl.sortPrint();
	cout<<endl;
	avl.remove(18);
	avl.sortPrint();
	cout<<endl;
	avl.remove(20);
	avl.sortPrint();
	cout<<endl;
	avl.remove(11);
	avl.sortPrint();
	cout<<endl;
	avl.remove(3);
	avl.sortPrint();
	cout<<endl;
	avl.remove(14);
	avl.sortPrint();
	cout<<endl;
	avl.remove(9);
	avl.sortPrint();
	cout<<endl;
//	*/
	return 0;
}
