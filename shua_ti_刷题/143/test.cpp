#include<iostream>
#include<vector>
#include<stack>
#include<deque>
using namespace std;
struct TreeNode 
{
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
vector<vector<int> > FindPath(TreeNode* root,int expectNumber) 
{
	vector<vector<int> > result;
	if(root == NULL)
	return result;

	vector<int> tmp ;
	deque<TreeNode*> dq;
	dq.push_back(root);
	int cursum = root->val;

	TreeNode* pre = NULL;
	TreeNode* cur = root;
	while( !dq.empty())
	{
		cur = dq.back();
		bool isLeaf = !cur->left && !cur->right;
		if(expectNumber == cursum && isLeaf)
		{
			tmp.clear();
			deque<TreeNode*>::iterator it = dq.begin();
			while(it != dq.end())
			{
				tmp.push_back((*it)->val);
				++it;
			}
			result.push_back(tmp);
		}
		if(cur->left)
		{	
			dq.push_back(cur->left);
			cursum += cur->left->val;
			continue;
		}
		if(cur->right)
		{
			dq.push_back(cur->right);
			cursum += cur->right->val;
			continue;
		}
		dq.pop_back();
		pre = dq.back();
		cursum -= cur->val;
		while(!dq.empty() && (pre->left == cur && pre->right == NULL || pre->right == cur))
		{
			dq.pop_back();
			cursum -= pre->val;
			cur = pre;
			if(!dq.empty())
			pre = dq.back();
			
		}
		if(pre->left == cur && pre->right)
		{
			dq.push_back(pre->right);
			cursum += pre->right->val;
			continue;
		}
	}
	return  result;
}

int main()
{
	TreeNode n1(10);
	TreeNode n2(5);
	TreeNode n3(2);
	TreeNode n4(4);
	TreeNode n5(7);
	TreeNode n6(3);
	TreeNode n7(33);

	n1.left = &n2;
//	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
//	n4.left = &n6;
	n5.left = &n7;
	vector<vector<int> >result;
	result = FindPath(&n1,22);
	vector<vector<int> >::iterator it = result.begin();
	while(it != result.end())
	{
		int size = (*it).size();
		for(int i =0;i< size;++i)
		{
			cout<<(*it)[i]<<"	";
		}
		cout<<endl;
		++it;
	}
		return 0;
}
