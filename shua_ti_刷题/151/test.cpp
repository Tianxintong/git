#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
	TreeNode(int v,TreeNode* l,TreeNode* r):val(v),left(l),right(r){}
};

void ConvertNode(TreeNode* root,TreeNode** LastNode)
{
	if(root == NULL)
	return;
	
	TreeNode* cur = root;

	if(cur->left)
	ConvertNode(cur->left,LastNode);
	
	cur->left = *LastNode;
	
	if(*LastNode)
	(*LastNode)->right = cur;

	*LastNode = cur;

	if(cur->right)
	ConvertNode(cur->right ,LastNode);
}

TreeNode* Convert(TreeNode* root)
{
	if(root == NULL)
	return NULL;

	TreeNode* LastNode = NULL;
	ConvertNode(root,&LastNode);

	TreeNode* head = LastNode;
	while(head && head->left)
	{
		head = head->left;
	}
	return head;
}

int main()
{
	TreeNode node4(4);	
	TreeNode node5(8);	
	TreeNode node6(12);	
	TreeNode node7(16);	
	TreeNode node2(6,&node4,&node5);	
	TreeNode node3(14,&node6,&node7);	
	TreeNode node1(10,&node2,&node3);	
	
	TreeNode* head = Convert(&node1);

	while(head)
	{
		cout<<head->val<<"	";
		head = head->right;
	}


	return 0;
}
