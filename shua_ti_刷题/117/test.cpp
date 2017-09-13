#include<iostream>
using namespace std;
struct TreeNode 
{
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
void preorder(TreeNode * root)
{
	if(root)
	cout<<root->val<<"	";
	preorder(root->left);
	preorder(root->right);
}
bool isequal(TreeNode *pRoot1,TreeNode*pRoot2)
{
	TreeNode *p1 = pRoot1;
	TreeNode* p2 = pRoot2;

	if( p2 == NULL)
	return true;

	if(p1 && p1->val == p2->val)
	{
		if(isequal(p1->left,p2->left))
		{
			return isequal(p1->right,p2->right);
		}
		else
		return false;
	}
	else
	return false;
	
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if(pRoot2 == NULL)
	return false;

	 if(pRoot1 == NULL )
	return false;
	
	TreeNode* p1 = pRoot1;
	TreeNode* p2 = pRoot2;
	bool result = false;
	while(p1 != NULL)
	{
		if( p1->val == p2->val)
		result = isequal(p1,p2);
		if( result )
		return result;
		if(result =  HasSubtree(p1->left,p2))
			return result;
		return HasSubtree(p1->right,p2);
	}
	return false;

}
int main()
{

//{8,#,8,#,9,#,2,#,5},{8,#,9,#,2}
	TreeNode t1(8);
	TreeNode t2(8);
	TreeNode t3(7);
	TreeNode t4(9);
	TreeNode t5(2);
	TreeNode t6(4);
	TreeNode t7(7);
	
//	t1.left = &t2;
	t1.right = &t2;
	t2.left = &t4;
	t2.right = &t5;
//	t5.left = &t6;
//	t5.right = &t7;

	TreeNode a1(8);
	TreeNode a2(9);
	TreeNode a3(2);
	a1.left = &a2;
	a1.right = &a3;

	cout<<	HasSubtree(&t1,&a1)<<endl;


	return 0;
}
