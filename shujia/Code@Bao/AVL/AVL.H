#pragma once

#include<stack>

template<class Type>
class AVLTree;

template<class Type>
class AVLNode
{
	friend class AVLTree<Type>;
public:
	AVLNode() : data(Type()),leftChild(NULL),rightChild(NULL),bf(0)
	{}
	AVLNode(Type d, AVLNode<Type>*left=NULL,AVLNode<Type>*right=NULL)
		: data(d),leftChild(left),rightChild(right),bf(0)
	{}
	~AVLNode()
	{}
public:
	void SetData(Type d);
	Type& GetData()const;
private:
	Type data;
	AVLNode *leftChild;
	AVLNode *rightChild;
	int bf;
};

template<class Type>
class AVLTree
{
public:
	AVLTree() : root(NULL)
	{}
public:
	void Insert(const Type &x)
	{
		Insert(root, x);
	}
private:
	void Insert(AVLNode<Type> *&rt, const Type &x)
	{
		AVLNode<Type> *pr = NULL;
		AVLNode<Type>*t = rt;
		stack<AVLNode<Type> *> St;

		while(t != NULL)
		{
			if(x == t->data)
				return;

			pr = t;
			St.push(pr);

			if(x < t->data)
				t = t->leftChild;
			else if(x > t->data)
				t = t->rightChild;
		}
		t = new AVLNode<Type>(x);
		if(rt == NULL)
		{
			rt = t;
			return;
		}

		if(x < pr->data)
			pr->leftChild = t;
		else 
			pr->rightChild = t;


		while(!St.empty())
		{
			pr = St.top();
			St.pop();

			if(pr->leftChild == t)
				pr->bf--;
			else
				pr->bf++;

			if(pr->bf == 0)
				break;
			else if(pr->bf==1 || pr->bf==-1)
				t = pr;
			else
			{
				//µ÷Õû
				if(pr->bf < 0)
				{
					if(t->bf < 0)   //     /
					{
						RotateR(pr);
					}
					else            //    <   
					{
						//RotateLR();
					}
				}
				else
				{
					if(t->bf > 0)   //    \  
					{
						//RaoteL();
					}
					else            //    >
					{
						//RotateRL()
					}
				}

				break;
			}
		}

		if(St.empty())
			rt = pr;
		else
		{
			AVLNode<Type> *s = St.top();
			if(pr->data < s->data)
				s->leftChild = pr;
			else
				s->rightChild = pr;
		}

	}
protected:
	AVLNode<Type>* RotateL(AVLNode<Type> *&ptr);
	AVLNode<Type>* RotateR(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subR = ptr;
		ptr = subR->leftChild;
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		ptr->bf = subR->bf = 0;
		return ptr;
	}
	AVLNode<Type>* RotateLR(AVLNode<Type> *&ptr);
	AVLNode<Type>* RotateRL(AVLNode<Type> *&ptr);
private:
	AVLNode<Type> *root;
};
