#pragma once 

typedef int Type;
typedef enum{RED = 0,BLACK}COLOR;

typedef struct RBNode
{
	COLOR color;
	Type data;
	struct	RBNode *parent;
	struct RBNode *leftChild;
	struct RBNode *rightChild;
}RBNode;

typedef struct RBTree
{
	RBNode *root;
	RBNode *NIL;
}RBTree;

void show_RBTree_1(RBTree &t,RBNode *r);
void show_RBTree(RBTree &t)
{
	RBNode *s = t.root;
	show_RBTree_1(t,t.root);
}
void show_RBTree_1(RBTree &t,RBNode *r)
{
	if(r!=t.NIL)
	{
		show_RBTree_1(t,r->leftChild);
		cout<<r->data<<"  ";
		show_RBTree_1(t,r->rightChild);
	}
}
RBNode* _Buynode(Type v)
{
	RBNode *s = (RBNode*)malloc(sizeof(RBNode));
	assert(s!=NULL);
	memset(s,0,sizeof(RBNode));
	s->color = RED;
	s->data = v;
	return s;
}
void Insert_Fixup(RBTree &t,RBNode *z);
void InitRBTree(RBTree &t)
{
	t.NIL = _Buynode(0);
	t.root = t.NIL;
	t.NIL->color = BLACK;
}
void LeftRotate(RBTree &t,RBNode *p)
{
	RBNode *s = p->rightChild;
	p->rightChild = s->leftChild;
	if(s->leftChild != t.NIL)
		s->leftChild->parent = p;
	s->parent = p->parent;
	if(p->parent ==t.NIL)
		t.root = s;
	else if(p == p->parent->leftChild)
		p->parent->leftChild = s;
	else
		p->parent->rightChild = s;
	s->leftChild = p;
	p->parent = s;

}
void RightRotate(RBTree &t,RBNode *p)
{
	RBNode *s = p->leftChild;
	p->leftChild = s->rightChild;
	if(s->rightChild != t.NIL)
		s->rightChild->parent = p;
	if(p->parent == t.NIL)
		t.root = s;
	else if(p->parent->leftChild == p)
		p->parent->leftChild = s;
	else
		p->parent->rightChild = s;
	
	s->rightChild = p;
	p->parent = s;
}
bool Insert(RBTree &t,Type x)
{
	RBNode *pr = t.NIL;
	RBNode *s =t.root;
	while(s!=t.NIL)
	{
		if(x == s->data)
		return false;

		pr = s;
		if(x<s->data)
			s = s->leftChild;
		else
			s = s->rightChild;
	}
	RBNode *q = _Buynode(x);
	q->leftChild = t.NIL;
	q->rightChild = t.NIL;
	q->color = RED;
	q->parent = pr;

	if(pr == t.NIL)
		t.root = q;
	if(x < pr->data)
		pr->leftChild = q;
	else
		pr->rightChild = q;
	
	Insert_Fixup(t,q);
	return true;
}
void Insert_Fixup(RBTree &t,RBNode *z)
{
	RBNode *y;//插入节点的父亲节点兄弟节点
	while(z->parent->color == RED)
	{
		if(z->parent == z->parent->parent->leftChild)
		{
			y = z->parent->parent->rightChild;
			if(y->color == RED)
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
				continue;
			}
			else if(z == z->parent->rightChild)
			{
				z = z->parent;
				LeftRotate(t,z);
			}
			z->parent->color = BLACK;
			z->parent->parent->color = RED;
			RightRotate(t,z->parent->parent);
		}
		else
		{
			y = z->parent->parent->rightChild;
			if(y->color == RED)
			{
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				y->color =BLACK;
				z = z->parent->parent;
				continue;
			}
			else if(z == z->parent->leftChild)
			{
				z = z->parent;
				LeftRotate(t,z);
			}
			z->parent->color = BLACK;
			z->parent->parent->color = RED;
			LeftRotate(t,z->parent->parent);
		}
	}
	t.root->color = BLACK;
}
void Delete_Fixup(RBTree &t,RBNode *&x)
{
	RBNode *w;
	while(x!=t.root && x->color == BLACK)
	{
		if( x == x->parent->leftChild)
		{
			w = x->parent->rightChild;
			if(w->color == RED)//1.w的颜色是红色，则x的父亲节点颜色一定是黑色，只要将x的父亲节点左旋转一次，然后改变P和w的颜色
			{
				w->color = BLACK;
				x->parent->color = RED;
				LeftRotate(t,x->parent);
			}
			if(w->leftChild->color == BLACK && w->rightChild->color == BLACK)//2.w是黑色的（其左右孩子节点一定是null,null，）将w改为红色，情况回到1,2,3,4,x=x->parent,继续向上检查
			{
				w->color = RED;
				x = x->parent;
			}
			else if(w->rightChild->color == BLACK)//3.w是黑色，左孩子节点是红色，右孩子节点是黑色null,w左旋，成为情况4
			{
				w->leftChild->color = BLACK;
				w->color = RED;
				RightRotate(t,w);
				w = x->parent->rightChild;
			}
			w->color = x->parent->color;//情况4
			x->parent->color = BLACK;
			w->rightChild->color = BLACK;
			LeftRotate(t,x->parent);
			x = t.root;//
		}
		else
		{
			w = x->parent->leftChild;
			if(w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				RightRotate(t,x->parent);
			}
			if(w->leftChild->color == BLACK && w->rightChild->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else if(w->leftChild->color == BLACK)
			{
				w->rightChild->color = BLACK;
				w->color = RED;
				LeftRotate(t,w);
				w = x->parent->leftChild;
			}
			w->color = x->parent->color;
			x->parent->color = BLACK;
			w->leftChild->color = BLACK;
			RightRotate(t,x->parent);
			x = t.root;
		}
	}
	t.root->color = BLACK;
}
RBNode* _Next(RBTree &t,RBNode *p)
{
	if(p!=t.NIL && p->rightChild != t.NIL)
	{
		p = p->rightChild;
		while(p->leftChild != t.NIL)
			p = p->leftChild;
	}
	return p;
}
bool  Remove(RBTree &t,Type key)
{
	RBNode *p = t.root;
	RBNode *y;
	RBNode *s;
	while(p!=t.NIL && p->data!=key)
	{
		if(key < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	if( p->leftChild!=t.NIL && p->rightChild != t.NIL)
	{
		y = _Next(t,p);
	}
	else
		y = p;
	if(y->leftChild != t.NIL)//s保存的是即将删除节点的仅有的孩子节点
		s = y->leftChild;
	else
		s = y->rightChild;

	s->parent = y->parent;
	if(y->parent == t.NIL)
		t.root = s;
	else if(y == y->parent->leftChild)
		y->parent->leftChild = s;
	else
		y->parent->rightChild = s;

	if(y != p)
		p->data = y->data;
	
	if(y->color == BLACK)
		Delete_Fixup(t,s);

	delete y;
	return true;
}
