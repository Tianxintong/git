#include<vector>
#include<iostream>
using namespace std;

//函数参数是vector<int> 的实现
// Definition for binary tree
struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) 
{
		if(pre.size() == 0 || vin.size() == 0)
				return NULL;
		int rootValue = pre[0];
		TreeNode* root = new TreeNode(rootValue);
		if(pre.size() == 1&& vin.size() == 1 && vin[0] == pre[0])
				return root;
		vector<int> leftSubPre;
		vector<int> rightSubPre;
		vector<int> leftSubIn;
		vector<int> rightSubIn;
		vector<int>::iterator it = vin.begin();

		int leftSubTreeLength = 0;
		while(it != vin.end()&& rootValue != *it)
		{
				leftSubIn.push_back(*it);
				++it;
				++leftSubTreeLength;
		}
		++it;
		int rightSubTreeLength = 0;
		while(it != vin.end())
		{
				rightSubIn.push_back(*it);
				++it;
				++rightSubTreeLength;
		}
		it = pre.begin();
		++it;
		int i =1;
		for(;i<leftSubTreeLength+1;++i)
		{
				leftSubPre.push_back(pre[i]);
		}
		for(;i<pre.size();++i)
		{
				rightSubPre.push_back(pre[i]);
		}
		if(leftSubTreeLength > 0)
				root->left = reConstructBinaryTree(leftSubPre,leftSubIn);
		if(rightSubTreeLength > 0)
				root->right = reConstructBinaryTree(rightSubPre,rightSubIn);
	return root;
}
void showInOrder(TreeNode *root)
{
		if( root == NULL)
				return;
		showInOrder(root->left);
		cout<<root->val<<" 	";
		showInOrder(root->right);
}

int main()
{
		vector<int>	Pre;
		Pre.push_back(1);
		Pre.push_back(2);
		Pre.push_back(4);
		Pre.push_back(7);
		Pre.push_back(3);
		Pre.push_back(5);
		Pre.push_back(6);
		Pre.push_back(8);
		vector<int> In;
		In.push_back(4);
		In.push_back(7);
		In.push_back(2);
		In.push_back(1);
		In.push_back(5);
		In.push_back(3);
		In.push_back(8);
		In.push_back(6);
		TreeNode* root = reConstructBinaryTree(Pre,In);
		showInOrder(root);
		return 0;
}
//参数为一般数组的实现
/*
   struct BinaryTreeNode
   {
   int  m_nValue;
   struct BinaryTreeNode* m_pLeft;
   struct BinaryTreeNode* m_pRight;
   BinaryTreeNode(int val):m_nValue(val),m_pLeft(NULL),m_pRight(NULL)
   {}
   };
   BinaryTreeNode* ConstructCore(int *startPreorder,int *endPreorder,int *startInorder,int *endInorder);
   BinaryTreeNode* Construct(int *preorder,int *inoder,int  length)
   {
   if(preorder == NULL ||inoder == NULL||length<=0)
   return NULL;
   return ConstructCore(preorder,preorder + length -1,inoder,inoder+length-1);
   }
   BinaryTreeNode* ConstructCore(int *startPreorder,int *endPreorder,int *startInorder,int *endInorder)
   {
   int rootValue = startPreorder[0];
   BinaryTreeNode* root = new BinaryTreeNode(rootValue);
   if(startPreorder == endPreorder && startInorder == endInorder && startInorder[0] == startPreorder[0])
   {
   return root;
   }
   int *rootInInoder = startInorder;
   while(rootInInoder != endInorder && rootValue != *rootInInoder)
   {
   ++rootInInoder;
   }

   int leftSubTreeLength = rootInInoder - startInorder;
   int rightSubTreeLength = endInorder - rootInInoder;
   if(leftSubTreeLength >0)
   {
   root->m_pLeft = ConstructCore(startPreorder+1,startPreorder+leftSubTreeLength,startInorder,rootInInoder-1);
   }
   if(rightSubTreeLength > 0)
   {
   root->m_pRight = ConstructCore(startPreorder+leftSubTreeLength+1,endPreorder,rootInInoder + 1,endInorder);
   }
   return root;

   }
   void showInOrder(BinaryTreeNode *root)
   {
   if( root == NULL)
   return;
   showInOrder(root->m_pLeft);
   cout<<root->m_nValue<<" 	";
   showInOrder(root->m_pRight);
   }
   int main()
   {
   int pre[] = {1,2,4,7,3,5,6,8};
   int in[] = {4,7,2,1,5,3,8,6};
   BinaryTreeNode* root = Construct(pre,in,8);
   showInOrder(root);
   cout<<endl;
   return 0;
   }
 */
