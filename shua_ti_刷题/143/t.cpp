#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;


struct BinaryTreeNode
{
	int val;
	BinaryTreeNode *left;
	BinaryTreeNode* right;
	BinaryTreeNode(int value):val(value),left(NULL),right(NULL)
	{}
};
void FindPath(BinaryTreeNode* pRoot,int expectedsum,vector<int> &path,int currentsum)
{
	currentsum += pRoot->val;
	path.push_back(pRoot->val);

	bool isLeaf = pRoot->left == NULL && pRoot->right == NULL;
	if(currentsum == expectedsum && isLeaf)
	{
		printf("A path is found:\n");
		vector<int>::iterator it = path.begin();
		while(it != path.end())
		{
			cout<<*it<<"	";
			++it;
		}
		cout<<endl;
	}
	if(pRoot->left)
	{
		FindPath(pRoot->left,expectedsum,path,currentsum);
	}
	if(pRoot->right)
	{
		FindPath(pRoot->right,expectedsum,path,currentsum);
	}
	path.pop_back();
}
void FindPath(BinaryTreeNode* pRoot,int expectedsum)
{
	if(pRoot == NULL)
	return ;

	vector<int> path;
	int currentsum = 0;
	FindPath(pRoot,expectedsum,path,currentsum);
}

int main()
{

	BinaryTreeNode n1(10);
	BinaryTreeNode n2(5);
	BinaryTreeNode n3(12);
	BinaryTreeNode n4(4);
	BinaryTreeNode n5(7);
	BinaryTreeNode n6(3);
	BinaryTreeNode n7(7);

	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n4.left = &n6;
	n5.left = &n7;
	FindPath(&n1,22);
	return 0;
}
