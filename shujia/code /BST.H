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
	BSTNode(Type d, BSTNode<Type> *left=NULL, BSTNode<Type> *right=NULL)
		: data(d), leftChild(left),rightChild(right)
	{}
	~BSTNode()
	{}
private:
	Type data;
	BSTNode *leftChild;
	BSTNode *rightChild;
};

template<class Type>
class BSTree
{
public:
	BSTree():root(NULL)
	{}
	BSTree(Type *ar, int n) : root(NULL)
	{
		for(int i=0; i<n; ++i)
		{
			Insert(ar[i]);
		}
	}
	~BSTree()
	{
		MakeEmpty();
	}
public:
	bool Insert(const Type &x)
	{
		return Insert(root, x);
	}
	Type& Max()
	{
		return Max(root);
	}
	//const Type& Max()const;
	Type& Min()
	{
		return Min(root);
	}
	const Type& Min()const;
	BSTNode<Type>* Search(const Type &key)const
	{
		return Search(root, key);
	}
	BSTNode<Type>* Parent(const Type &key)const
	{
		return Parent(root, key);
	}
	void SortPrint()const
	{
		SortPrint(root);
	}
	
	bool Equal(const BSTree<Type> &bst)const
	{
		return Equal(root, bst.root);
	}

	//bst1.Copy(bst);
	void Copy(const BSTree<Type> &bst)
	{
		root = Copy(bst.root);
	}

	///////////////////////////////////////////////////////////
	bool Remove(const Type &key)
	{
		return Remove(root, key);
	}
protected:
	void MakeEmpty()
	{
		MakeEmpty(root);
	}
protected:
	bool Remove(BSTNode<Type> *&t, const Type &key)
	{
		if(t == NULL)
			return false;
		if(key < t->data)
			Remove(t->leftChild, key);
		else if(key > t->data)
			Remove(t->rightChild, key);
		else
		{
			if(t->leftChild==NULL && t->rightChild==NULL)
			{
				delete t;
				t = NULL;
			}
			else if(t->leftChild!=NULL && t->rightChild==NULL)
			{
				BSTNode<Type> *p = t;
				t = p->leftChild;
				delete p;
			}
			else if(t->leftChild==NULL && t->rightChild!=NULL)
			{
				BSTNode<Type> *p = t;
				t = p->rightChild;
				delete p;
			}
			else
			{
				BSTNode<Type> *p = t->rightChild;
				while(p->leftChild != NULL)
					p = p->leftChild;
				t->data = p->data;
				Remove(t->rightChild, p->data);
			}

			return true;
		}
	}
	void MakeEmpty(BSTNode<Type> *&t)
	{
		if(t != NULL)
		{
			MakeEmpty(t->leftChild);
			MakeEmpty(t->rightChild);
			delete t;
		}
	}
	bool Equal(BSTNode<Type> *t1, BSTNode<Type> *t2)const
	{
		if(t1==NULL && t2==NULL)
			return true;
		if(t1!=NULL &&  t2!=NULL &&t1->data==t2->data
			&& Equal(t1->leftChild, t2->leftChild)
			&& Equal(t1->rightChild, t2->rightChild))
			return true;
		return false;
	}

	BSTNode<Type>* Copy(BSTNode<Type> *t)
	{
		if(t == NULL)
			return NULL;
		BSTNode<Type> *s = new BSTNode<Type>(t->data);
		s->leftChild = Copy(t->leftChild);
		s->rightChild = Copy(t->rightChild);
		return s;
	}
	void SortPrint(BSTNode<Type> *t)const
	{
		if(t != NULL)
		{
			SortPrint(t->leftChild);
			cout<<t->data<<" ";
			SortPrint(t->rightChild);
		}
	}
	BSTNode<Type>* Parent(BSTNode<Type> *t, const Type &key)const
	{
		BSTNode<Type> *p = Search(t, key);
		if(p==NULL || t==NULL || key==t->data)
			return NULL;

		if(t->leftChild==p || t->rightChild==p)
			return t;
		if(key < t->data)
			Parent(t->leftChild, key);
		else if(key > t->data)
			Parent(t->rightChild, key);
	}
	BSTNode<Type>* Search(BSTNode<Type> *t, const Type &key)const
	{
		if(t == NULL)
			return NULL;
		if(t->data == key)
			return t;
		else if(key < t->data)
			 Search(t->leftChild, key);
		else
			Search(t->rightChild, key);
	}

	Type& Max(BSTNode<Type> *t)
	{
		BSTNode<Type> *p = t;
		while(p->rightChild != NULL)
			p = p->rightChild;
		return p->data;
	}
	Type& Min(BSTNode<Type> *t)
	{
		BSTNode<Type> *p = t;
		while(p->leftChild != NULL)
			p = p->leftChild;
		return p->data;
	}
	bool Insert(BSTNode<Type> *&t, const Type &x)
	{
		if(t == NULL)

		{
			t = new BSTNode<Type>(x);
			return true;
		}
		else if(x < t->data)
			Insert(t->leftChild, x);
		else if(x > t->data)
			Insert(t->rightChild, x);
		else 
			return false;
	}
private:
	BSTNode<Type> *root;
};


