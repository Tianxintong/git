#include<iostream>
using namespace std;

#include"./AVL.h"

int main()
{
	AVLTree<int> avl;
	int ar[11] = {16,3,7,11,8,20,9,26,18,14,15};
	for(int i=0;i<11;i++)
	avl.Insert(ar[i]);
	avl.remove(3);
	avl.sortPrint();
	cout<<endl;
	return 0;
}
