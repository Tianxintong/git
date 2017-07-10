#include<iostream>
#include<vld.h>
using namespace std;

#include"BST.h"

void main()
{
	int ar[] = {53, 78, 65, 17, 87, 9, 81, 45, 23};
	int n = sizeof(ar) / sizeof(int);

	BSTree<int> bst(ar, n);

	bst.Remove(78);
}

/*
void main()
{
	int ar[] = {53, 78, 65, 17, 87, 9, 81, 45, 23};
	int n = sizeof(ar) / sizeof(int);

	BSTree<int> bst(ar, n);

	cout<<"Max Value = "<<bst.Max()<<endl;
	cout<<"Min Value = "<<bst.Min()<<endl;

	BSTNode<int> *p = bst.Search(17);
	BSTNode<int> *pa = bst.Parent(23);

	bst.SortPrint();
	cout<<endl;

	BSTree<int> bst1;
	bst1.Copy(bst);

	bool flag = bst.Equal(bst1);
	cout<<"flag = "<<flag<<endl; 

	return;
}

/*
void main()
{
	int ar[] = {53, 78, 65, 17, 87, 9, 81, 45, 23};
	int n = sizeof(ar) / sizeof(int);

	BSTree<int> bst;

	for(int i=0; i<n; ++i)
	{
		bst.Insert(ar[i]);
	}
	return;
}
*/