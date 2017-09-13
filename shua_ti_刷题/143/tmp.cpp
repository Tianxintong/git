vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<vector<int> > result;
		if(root == NULL)
				return result;

		vector<int> tmp ;
		stack<TreeNode*> st;
		st.push(root);
		int cursum = root->val;

		TreeNode* pre = NULL;
		TreeNode* cur = root;
		while( !st.empty())
		{
				cur = st.top();
				bool isLeaf = !cur->left && !cur->right;
				if(expectNumber == cursum && isLeaf)
				{
						tmp.clear();
						//put the path into vector<vector<int> >
						stack<TreeNode*> t;
						while(!st.empty())
						{
								t.push(st.top());
								st.pop();
						}
						while(!t.empty())
						{
								tmp.push_back(t.top()->val);
								//			cout<<t.top()->val<<"	";
								st.push(t.top());
								t.pop();
						}
						result.push_back(tmp);
						//			cout<<endl;
				}
				if(cur->left)
				{	
						st.push(cur->left);
						cursum += cur->left->val;
						continue;
				}
				if(cur->right)
				{
						st.push(cur->right);
						cursum += cur->right->val;
						continue;
				}
				st.pop();
				pre = st.top();
				cursum -= cur->val;
				while(!st.empty() && (pre->left == cur && pre->right == NULL || pre->right == cur))
				{
						st.pop();
						cursum -= pre->val;
						cur = pre;
						if(!st.empty())
								pre = st.top();

				}
				if(pre->left == cur && pre->right)
				{
						st.push(pre->right);
						cursum += pre->right->val;
						continue;
				}
		}
		return  result;

}
