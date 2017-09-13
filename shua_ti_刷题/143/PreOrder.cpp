#include<iostream>
#include<stack>
using namespace std;

template<class Type>
void BinTree<Type>::PreOrder_1(BinTreeNode<Type> *t)const//前序遍历的非递归版本实现
{
		stack<BinTreeNode<Type>*  >st;
		if(t!=NULL)
		{
				st.push(t);
				while(!st.empty())
				{
						t=st.top();
						st.pop();
						cout<<t->data<<"  ";
						if(t->rightChild!=NULL)
								st.push(t->rightChild);
						if(t->leftChild!=NULL)
								st.push(t->leftChild);
				}
		}
}
