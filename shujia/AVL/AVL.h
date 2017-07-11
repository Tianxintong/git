#pragma once

#include<stack>

template<class Type>
class AVLTree;

template<class Type>
class AVLNode
{
friend class AVLTree<Type>;
public:
	AVLNode():data(Type()),leftChild(NULL),rightChild(NULL)
	{}
	AVLNode(Type d,AVLNode<Type>* left = NULL,AVLNode<Type>* right = NULL):data(d),leftChild(left),rightChild(right),bf(0)
	{}
	~AVLNode()
	{}
private:
	void SetData(Type d);
	Type& GetData()const;

	Type data;
	AVLNode<Type>* leftChild;
	AVLNode<Type>* rightChild;
	int bf;
};

template<class Type>
class AVLTree
{
public:
	AVLTree():root(NULL)
	{}
	void Insert(const Type &x)
	{
		Insert(root,x);
	}
	void remove(const Type &x)
	{
		remove(root,x);
	}
	void sortPrint()
	{	
		sortPrint(root);
	}
protected:
	void sortPrint(AVLNode<Type>* root)
	{
		AVLNode<Type>* s = root;
		if(s)
		{
			sortPrint(s->leftChild);
			cout<<s->data<<"  ";
			sortPrint(s->rightChild);
		}
	}
	AVLNode<Type>* RotateL(AVLNode<Type> *&ptr)
	{
		AVLNode<Type>* subL = ptr;
		ptr = subL->rightChild;
		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		ptr->bf = subL->bf = 0;
		return ptr;
	}
	AVLNode<Type>* RotateR(AVLNode<Type> *&ptr)
	{
		AVLNode<Type>* subR = ptr;
		ptr = subR->leftChild;
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		ptr->bf = subR->bf = 0;
		return ptr;
	}
	AVLNode<Type>* RotateLR(AVLNode<Type> *&ptr)
	{
		AVLNode<Type>* subR = ptr;
		AVLNode<Type>* subL = subR->leftChild;
		ptr = subL->rightChild;
	//先左旋
		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		if(ptr->bf<=0)
			subL->bf = 0;
		else
			subL->bf = -1;
	//然后右旋
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		if(ptr->bf>=0)
			subR->bf = 0;
		else
			subR->bf = 1;
		ptr->bf = 0;
		return ptr;
	}
	AVLNode<Type>* RotateRL(AVLNode<Type> *&ptr)//  >
	{
		AVLNode<Type>* subL = ptr;
		AVLNode<Type>* subR = ptr->rightChild;
		ptr = subR->leftChild;
		//先右旋
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		if(ptr->bf>=0)
		subR->bf = 0;
		else 
		subR->bf = 1;
		//然后左旋
		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		if(ptr->bf<=0)
		subL->bf = 0;
		else
		subL->bf = -1;

		ptr->bf = 0;
		return ptr;
	}
private:
	void Insert(AVLNode<Type> *&rt,const Type x)
	{
		stack<AVLNode<Type>* > St;
		AVLNode<Type>* pr = NULL;
		AVLNode<Type>* t = rt;

		//查找x要插入的位置，并插入，记录下行路线
		while(t)
		{
			if(x == t->data)
			return;
			pr = t;
			St.push(pr);

			 if(x<t->data)
			t=t->leftChild;
			else if(x>t->data)
			t=t->rightChild;
		}

		t = new AVLNode<Type>(x);
		if(rt == NULL)
		{
			rt = t;
			return ;
		}
		if(x < pr->data)
		pr->leftChild = t;
		else
		pr->rightChild = t;


		while(!St.empty())//修正平衡因子，调整平衡
		{
			pr = St.top();
			St.pop();

			if(pr->leftChild == t)
			pr->bf--;
			else 
			pr->bf++;

			if(pr->bf == 0)
				break;
			else if(pr->bf == -1||pr->bf == 1)
			{
				t = pr;
			}
			else
			{
				if(pr->bf<0)
				{
					if(t->bf<0)
					{
						RotateR(pr);
					}
					else
					{
						RotateLR(pr);
					}
				}
				else
				{
					if(t->bf > 0)
					{
						RotateL(pr);
					}
					else
					{
						RotateRL(pr);
					}
				}
				break;
			}
		}
		if(St.empty())
			rt = pr;
		else
		{
			//新根结点连接原来的结点
			AVLNode<Type> *s = St.top();
			if(pr->data < s->data)
				s->leftChild = pr;
			else 
				s->rightChild = pr;
		}
	}
	bool remove(AVLNode<Type>*& t,const Type&x)
	{
		if(t==NULL)
			return false;
		AVLNode<Type>* p = t;
		AVLNode<Type>* q;
		AVLNode<Type>*pr = NULL;
		stack< AVLNode<Type>* > st;

		while(p)
		{
			if(p->data == x)
				break;
			pr = p;
			st.push(pr);
			if(x<p->data)
				 p=p->leftChild;
			else
				p = p->rightChild;
		}
		if(p == NULL)//没有找到要删除的结点
		return false;
		if(p->leftChild!=NULL&&p->rightChild!=NULL)//删除的结点左右孩子均存在
		{
			pr = p;
			st.push(pr);

			q = q->leftChild;
			while(q->rightChild)
			{
				pr = q;
				q = q->rightChild;
			}
			p->data = q->data;
			p = q;//p指向要删除的结点
		}
		
		if(p->leftChild!=NULL)
			q = p->leftChild;
		else
			q = p->rightChild;
		if(pr == NULL)//要删除的结点是root结点
			t = q;
		else
		{
			if(pr->leftChild == p)
				pr->leftChild = q;
			else
				pr->rightChild = q;

			while(!st.empty())
			{
				pr = st.top();
				st.pop();

				if(pr->leftChild == q)
					pr->bf++;
				else
					pr->bf--;
				if(pr->bf == -1||pr->bf == 1)
					break;
				else if(pr->bf == 0)
					q = pr;
				else
				{
					if(pr->bf > 0)
						q = pr->rightChild;
					else
						q = pr->leftChild;

					if(q->bf == 0)
					{
						if(pr->bf > 0)
						{
							//RotateL(pr)
							//bf
						}
						else
						{
							//RotateR(pr)
							//pr->bf
								//pr->rightChild->bf
						}
					}
					else if(q->bf  > 0)
					{
						if(pr->bf > 0)
						{
								RotateL(pr);
						}
						else
						{
								RotateLR(pr);
						}
						break;
					}
					else
					{
						if(pr->bf<0)
						RotateR(pr);
						else
						RotateRL(pr);
					}
					break;
				}
			}
			AVLNode<Type> *ppr = st.top();
			if(ppr->data > pr->data)
			ppr->leftChild = pr;
			else
			ppr->rightChild = pr;
		}
	delete p;
	return true;

	}
	AVLNode<Type> *root;
};
