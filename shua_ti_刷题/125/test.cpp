#include<iostream>
#include<stack>
using namespace std;

struct TreeNode 
{
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

void Mirror(TreeNode *pRoot)
{
	if(!pRoot)
		return;
	if(!pRoot->left && !pRoot->right)
		return;

	stack<TreeNode*> st;
	st.push(pRoot);
	while(!st.empty())
	{
		TreeNode* p = st.top();
		st.pop();
		TreeNode* tmp = p->left;
		p->left = p->right;
		p->right = tmp;
		if(p->left)
		st.push(p->left);
		if(p->right)
		st.push(p->right);
	}
}
/*
void Mirror(TreeNode *pRoot) //recursive method
{
	if( !pRoot)
	return;

	TreeNode* tmp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = tmp;

	Mirror(pRoot->left);
	Mirror(pRoot->right);
}
*/
int main()
{
	TreeNode t1(8);
	TreeNode t2(6);
	TreeNode t3(10);
	TreeNode t4(5);
	TreeNode t5(7);
	TreeNode t6(9);
	TreeNode t7(11);
	
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t4.left = &t7;
	Mirror(&t1);

		return 0;
}
