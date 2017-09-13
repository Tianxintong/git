#include<iostream>
using namespace std;

struct RandomListNode 
{
		int label;
		struct RandomListNode *next, *random;
		RandomListNode(int x) :label(x), next(NULL), random(NULL){}
};

void CloneNodes(RandomListNode* pHead)
{
	RandomListNode* pNode = pHead;
	while(pNode)
	{
		RandomListNode* pClone = new RandomListNode(pNode->label);
		pClone->next = pNode->next;

		pNode->next = pClone;

		pNode = pClone->next;
	}
}

void ConnectRandomNodes(RandomListNode* pHead)
{
	RandomListNode* pNode = pHead;
	while(pNode)
	{
		RandomListNode* pClone = pNode->next;
		if(pNode->random )
		{
			pClone->random = pNode->random->next;
		}
		if(pClone && pClone->next)
		pNode = pClone->next;
		else
		pNode = NULL;
	}
}

RandomListNode*  ReconnectNodes(RandomListNode* pHead)
{
	RandomListNode* pNode = pHead;
	RandomListNode* pCloneHead = NULL;
	RandomListNode* pCloneNode = NULL;
	if(pNode)
	{
		pCloneHead =pCloneNode =  pNode->next;
		pNode->next = pCloneNode->next;
		pNode = pNode->next;
	}
	while(pNode)
	{
		pCloneNode->next = pNode->next;
		pCloneNode = pCloneNode->next;
		if(pCloneNode )
		{
			pNode->next = pCloneNode->next;
			pNode = pNode->next;
		}
		else
		pNode = NULL;
	}
	return pCloneHead;
}
RandomListNode* Clone(RandomListNode* pHead)
{
	CloneNodes(pHead);
	ConnectRandomNodes(pHead);
	return ReconnectNodes(pHead);
}

int main()
{
	RandomListNode n1(1);
	RandomListNode n2(2);
	RandomListNode n3(3);
	RandomListNode n4(4);
	RandomListNode n5(5);
	RandomListNode n6(3);
	RandomListNode n7(5);
	RandomListNode n8(2);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	n7.next = &n8;
	n6.random = &n2;
	n7.random = &n5;

	RandomListNode* ret =  Clone(&n1);

	while(ret)
	{
		cout<<ret->label<<"	";
		ret = ret->next;
	}
	cout<<endl;

	return 0;

}
