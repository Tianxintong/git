#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode
{
		int value;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int val):value(val),left(NULL),right(NULL){}
};
void TreePreOrder(TreeNode* root)
{
		if(root == NULL)
				return;
		cout<<root->value<<"	";
		TreePreOrder(root->left);
		TreePreOrder(root->right);
}
void Traverse_TreeInPreOrder(std::vector<int> &values, TreeNode* root)
{
	if(root == NULL)
	return;
		stack< TreeNode*> st;
		st.push(root);
		TreeNode* p = root;
		TreeNode* last_top;
		while(!st.empty())
		{
			while(p)
			{
				cout<<p->value<<"	";
				st.push(p);
				p = p->left;
			}
			while(!st.empty() && st.top()->right == NULL)
			{
				st.pop();
			}
			last_top = st.top();
			p = last_top->right;
			st.pop();
		}
}
int main()
{

		TreeNode node1(1);
		TreeNode node2(2);
		TreeNode node3(3);
		TreeNode node4(4);
		TreeNode node5(5);
		TreeNode node6(6);
		TreeNode node7(7);
		TreeNode node8(8);
		node1.left = &node2;
		node1.right = &node3;
		node2.left = &node4;
		node2.right = &node5;
		node4.left = &node6;
		node3.left = &node7;
		node3.right = &node8;
		TreePreOrder(&node1);
		cout<<endl;
		vector<int> vec;
		Traverse_TreeInPreOrder(vec,&node1);
		cout<<endl;
		return 0;
}
