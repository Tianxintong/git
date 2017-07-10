#pragma once


template<class Type>
class BSTree;

template<class Type>
class BSTNode
{
friend class BSTree<Type>;
public:
	BSTNode():data(Type()),leftChild(NULL),rightChild(NULL)
	{}
	BSTNode(Type d,BSTNode<Type>* left=NULL,BSTNode<Type>* right=NULL):data(d),leftChild(left),rightChild(right)
	{}
	~BSTNode()
	{}
private:
	Type data;
	BSTNode<Type>* leftChild;
	BSTNode<Type>* rightChild;
};

template<class Type>
class BSTree
{
public:
	BSTree():root(NULL)
	{}
	BSTree(Type *ar,int n):root(NULL)
	{
		for(int i=0;i<n;++i)
		Insert(ar[i]);
	}
	bool Insert(const Type &x)
	{
		Insert(root,x);
	}
	bool Insert(BSTNode<Type>* &t,const Type& x)
	{
		if(NULL==t)
		{
			t=new BSTNode<Type>(x);
			return true;
		}
		else if(x<t->data)
			return Insert(t->leftChild,x);
		else if(x>t->data)
			return Insert(t->rightChild,x);
		else
			return false;
	}
	void sortPrint()
	{
		sortPrint(root);
	}
	void sortPrint(BSTNode<Type>* t)
	{
		if(NULL != t)
		{
			sortPrint(t->leftChild);
			cout<<t->data<<"  ";
			sortPrint(t->rightChild);
		}
	}
	Type& Max()
	{
		BSTNode<Type>* t = root;
		while(t!=NULL)
		{
			if(t->rightChild!=NULL)
			t=t->rightChild;
			else
			return t->data;
		}
		return -1;
	}
	const Type& Max()const;
	Type& Min()
	{
		BSTNode<Type> *t= root;
		while(t!=NULL)
		{
			if(t->leftChild)
			{
				t=t->leftChild;
			}
			else
			return t->data;
		}
		return -1;
	}
	const Type& Min()const;
	bool Parent(BSTNode<Type>* t);
	bool Remove(const Type &key);
	BSTNode<Type>* Search(const Type &key)const;
	bool Equal(const Type &key)const;
	void copy(BSTree<Type>&bst);
private:
	BSTNode<Type>* root;
};
