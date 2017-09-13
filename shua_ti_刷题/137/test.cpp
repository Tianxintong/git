#include<iostream>
#include<queue>
using namespace std;
struct TreeNode 
{
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
vector<int> PrintFromTopToBottom(TreeNode* root)
{
	vector<int> result;
	if(root == NULL)
	return result;
	
	queue<TreeNode*> q;
	q.push(root);
	
	TreeNode* tmp;
	while(!q.empty())
	{
		tmp = q.front();
		result.push_back(tmp->val);
		q.pop();
		if(tmp->left !=  NULL)
		q.push(tmp->left);
		if(tmp->right != NULL)
		q.push(tmp->right);
	}
	return result;
}

int main()
{

	TreeNode n1(8);
	TreeNode n2(6);
	TreeNode n3(10);
	TreeNode n4(5);
	TreeNode n5(7);
	TreeNode n6(9);
	TreeNode n7(11);

	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.left = &n6;
	n3.right = &n7;

	vector<int> result = PrintFromTopToBottom(&n1);

	int i = 0;
	int n = result.size();
	for(;i<n;++i)
	cout<<result[i]<<"	";
	cout<<endl;

	
		return 0;
}
