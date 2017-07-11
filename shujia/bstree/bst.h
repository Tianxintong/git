#pragma once

template<class Type>
class BSTree;

template<class Type>
class BSTNode
{
	friend BSTree<Type>;
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
	~BSTree()
	{}
	bool Insert(const Type x)
	{
		return Insert(root,x);
	}
	Type & Max()
	{
		Max(root);
	}
	Type& Min()
	{
		return Min(root);
	}
	void sortPrint()
	{
		sortPrint(root);
	}
	BSTNode<Type>* Parent(Type key)
	{
		Parent(root,key);
	}
	BSTNode<Type>* Search(Type key)
	{
		Search(root,key);
	}
	bool remove(Type key)
	{
		remove(root,key);
	}
	bool Copy(const BSTree<Type> &bst)
	{
		root = Copy(bst.root);
	}
	void MakeEmpty()
	{
		MakeEmpty(root);
	}
	bool Equal(const BSTree<Type> &bst)const
	{
		return Equal(root,bst.root);
	}
protected:
	bool Equal(BSTNode<Type> *t1,BSTNode<Type>* t2)const
	{
		if(t1 == NULL&&t2==NULL)
		return true;
		if(t1!=NULL&&t2!=NULL && t1->data==t2->data&&Equal(t1->leftChild,t2->leftChild)&&Equal(t1->rightChild,t2->rightChild))
		return true;
		return false;
	}
	void MakeEmpty(BSTNode<Type> *t)
	{
		if(t!=NULL)
		{
			MakeEmpty(t->leftChild);
			MakeEmpty(t->rightChild);
			delete t;
		}
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
	bool remove(BSTNode<Type>* &p,Type key)
	{
		BSTNode<Type>* s=NULL;
		if(p==NULL)
		return false;
		else if(key<p->data)
		remove(p->leftChild,key);
		else if(key>p->data)
		remove(p->rightChild,key);
		else
		{
		if(p->leftChild && p->rightChild==NULL)
		{
			s=p;
			p=p->leftChild;
			delete s;
			return true;
		}
		else if(p->rightChild && p->leftChild==NULL)
		{
			s=p;
			p=p->rightChild;
			delete s;
			return true;
		}
		else if(p->leftChild==NULL&&p->rightChild==NULL)
		{
			delete p;
			p=NULL;
			return true;
		}
		else
		{
			BSTNode<Type>* tm=p->rightChild;
			while(tm->leftChild)
			{
				tm = tm->leftChild;
			}
			p->data = tm->data;
			remove(p->rightChild,tm->data);
			return true;
		}
		}
	}

	
	BSTNode<Type>* Search(BSTNode<Type>* t,Type key)
	{
		if(t==NULL)
		return NULL;
		if(t->data == key)
		return t;
		else if(key<t->data)
		return Search(t->leftChild,key);
		else if(key>t->data)
		return Search(t->rightChild,key);
	}
	BSTNode<Type>* Parent(BSTNode<Type>* t,Type key)
	{
		BSTNode<Type>* p = Search(t,key);
		if(t==NULL||p==NULL||t->data==key)
		return NULL;

		while(t)
		{
			if(t->leftChild==p||t->rightChild==p)
			{
				cout<<"Parent value = "<<t->data<<endl;
				return t;
			}
			else if(key>t->data)
			t=t->rightChild;
			else 
			t=t->leftChild;
		}
	}
	void sortPrint(BSTNode<Type>* t)
	{
		if(t)
		{
			sortPrint(t->leftChild);
			cout<<t->data<<"  ";
			sortPrint(t->rightChild);
		}
	}
	Type& Min(BSTNode<Type>* t)
	{
		while(t->leftChild)
		t=t->leftChild;
		return t->data;
	}
	Type& Max(BSTNode<Type>* t)
	{
		while(t->rightChild)
		t=t->rightChild;
		return t->data;
	}
	bool Insert( BSTNode<Type> *&t,const Type x)
	{
		if(NULL==t)
		{
			t=new BSTNode<Type>(x);
			return true;
		}
		else if(x < t->data)
			return 	Insert(t->leftChild,x);
		else if(x > t->data)
			return Insert(t->rightChild,x);
		else
		return false;
	}
private:
	BSTNode<Type>* root;
};
