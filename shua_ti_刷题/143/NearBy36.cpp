

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL){}
}

vector<vector<int> > FindPath(TreeNode *root, int expectNumber){
		vector<vector<int> > res;   
		if (root == NULL)
				return res;
		stack<TreeNode *> s;
		s.push(root);
		int sum = 0; //当前和
		vector<int> curPath; //当前路径
		TreeNode *cur = root; //当前节点
		TreeNode *last = NULL; //保存上一个节点
		while (!s.empty()){
				if (cur == NULL){
						TreeNode *temp = s.top();
						if (temp->right != NULL && temp->right != last){
								cur = temp->right; //转向未遍历过的右子树
						}else{
								last = temp; //保存上一个已遍历的节点
								s.pop();
								curPath.pop_back(); //从当前路径删除
								sum -= temp->val;
						}  }
				else{
						s.push(cur);
						sum += cur->val;
						curPath.push_back(cur->val);
						if (cur->left == NULL && cur->right == NULL && sum == expectNumber){
								res.push_back(curPath);
						}
						cur = cur->left; //先序遍历，左子树先于右子树
				}
		}
		return res;
}

