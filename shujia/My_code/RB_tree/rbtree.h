#pragma  once 

typedef enum {RED,BLACK} COLOR;

template<class Type>
class RBTree;

template<class Type>
class RBNode
{
	friend class RBTree<Type>;
public:
	RBNode():data(Type()),color(RED),parent(NULL),leftChild(NULL),rightChild(NULL)
	{}
	RBNode(Type d,COLOR c = RED,RBNode<Type>* p =NULL,RBNode<Type>* left = NULL,RBNode<Type>* right = NULL):data(d),color(c),parent(p),leftChild(left),rightChild(right)
	{}
	~RBNode()
	{}
private:
	Type data;
	RBNode<Type> *leftChild;
	RBNode<Type> *rightChild;
	RBNode<Type> *parent;
	COLOR color;
};

template<class Type>
class RBTree
{
public:
	RBTree():root(NULL)
	{}
	bool  Insert(const Type &v)
	{
		Insert(root,v);
	}
protected:
	bool Insert(RBNode<Type>* &t,const Type &v)
	{
		RBNode<Type> *x = t;
		RBNode<Type>* pr = NULL;
		while(x!=NULL)
		{
			if(v == x->data)
			return false;
			pr = x;

			if(v<x->data)
			x = x->leftChild;
			else
			x = x->rightChild;
		}
		x = _Buynode(v);
		if(pr == NULL)
		{
			t = x;
			t->color = BLACK;
			return true;
		}
		if(v < pr->data)

		pr->leftChild = x;
		else
		pr->rightChild = x;

		x->parent = pr;

		_Balance_Tree(t,x);

		return true;
	}
	void _Balance_Tree(RBNode<Type> *&t,RBNode<Type> *x)
	{
		RBNode<Type> *s;
		while(x->parent->color == RED)
		{
			if(x->parent == x->parent->parent->leftChild)
			{
				RBNode<Type> *s = x->parent->parent->rightChild;
				if((x == x->parent->leftChild&& s == NULL) || ( x == x->leftChild && (s!=NULL&&s->color == BLACK)))
				{
					x->parent->color = BLACK;
					x->parent->parent->color = RED;
					RotateR(x->parent->parent);
				}
				else if((x==x->parent->rightChild && s== NULL)||(x==x->parent->rightChild&&s!=NULL&&s->color==BLACK))
				{
				//?
					RotateL	(x->parent);
					x->parent->parent = RED;
					x->color = BLACK;
					RotateR(x->parent->parent);

				}
				else if((x ==x->parent->leftChild && s->color==RED))
				{
					
				}
				else if((x==x->parent->rightChild && s->color == RED))
				{

				}
			}
		}
	}
	void RotateR(RBTree<Type>* ptr)
	{
		RBNode<Type>* subR = ptr;
		ptr = subR->leftChild;
		subR->leftChild = ptr->rightChild;
		if(ptr->rightChild!=NULL)
		{
			ptr->rightChild->parent = subR;
		}
		
		if(subR->parent == NULL)
		{
			root = ptr;
		}
		else
		{
			if(subR ==subR->parent->leftChild)
			subR->parent->leftChild = ptr;
			else
			subR->parent->rightChild = ptr;
		}
		ptr->parent = subR->parent;

		ptr->rightChild = subR;
		subR->parent = ptr;
	}
private:
RBNode<Type>* _Buynode(const Type &v)
{
	RBNode<Type> *s = new RBNode<Type>(v);
	assert(s!=NULL);
	return s;
}
RBNode<Type> *root;
};
