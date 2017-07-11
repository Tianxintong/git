#include<iostream>
using namespace std;
#include"./bst.h"
int main()
{
	int ar[10] = {8,99,6,44,3,1,2,88,0,9};
	BSTree<int> bst(ar,10);
	bst.sortPrint();
	cout<<endl;
	cout<<"Max value = "<<bst.Max()<<endl;
	cout<<"Min Value = "<<bst.Min()<<endl;
	bst.Search(88);
	bst.Parent(88);
	bst.remove(8);
	bst.sortPrint();
	cout<<endl;
	int r[10] ={9,7,64,2,1,3,5,68,999,0};
	BSTree<int> bst1(r,10);
	bst1.sortPrint();
	cout<<endl;
	bst.Copy(bst1);
	bst.sortPrint();
	cout<<endl;
	cout<<bst.Equal(bst1)<<endl;;
	return 0;
}
