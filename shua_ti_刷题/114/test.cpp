#include<iostream>
using namespace std;

struct ListNode 
{
		int val;
		struct ListNode *next;
		ListNode(int x):val(x), next(NULL) {}
};
/*  //the answer of  book
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if(pHead1 == NULL)
	return pHead2;
	else if( pHead2 == NULL)
	return pHead1;

	ListNode* pMergeHead = NULL;

	if(pHead1->val < pHead2->val)
	{
		pMergeHead = pHead1;
		pMergeHead->next = Merge(pHead1->next,pHead2);
	}
	else
	{
		pMergeHead = pHead2;
		pMergeHead->next = Merge(pHead1,pHead2->next);
	}
	return pMergeHead;
}
*/
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)//right answer
{
		if(pHead1 == NULL )
				return pHead2;
		else if(pHead2 == NULL )
				return pHead1;

		ListNode *p1 = pHead1;
		ListNode* p2 = pHead2;
		ListNode *pre = NULL;
		ListNode *head = pHead1;
		if(pHead1->val > pHead2->val)
			head = pHead2;
		while(p1 && p2)
		{
				if(p1->val <= p2->val)
				{
						while(p1 && p2 && p1->val <= p2->val)
						{
								pre = p1;
								p1 = p1->next;
						}
						pre->next = p2;
				}
				else
				{
						while( p2 && p2 && p1->val > p2->val)
						{
								pre = p2;
								p2 = p2->next;
						}
						pre->next = p1;
				}
		}
		return head;
}

int main()
{
	ListNode n1(1);
	ListNode n3(3);
	ListNode n5(5);
	ListNode n7(5);
	ListNode n8(10);
	ListNode n10(10);


	ListNode n2(1);
	ListNode n4(3);
	ListNode n6(5);
	ListNode n9(9);
	n1.next = &n3;
	n3.next = &n5;
	n5.next = &n7;
	n7.next = &n8;
	n8.next = &n10;


	n2.next = &n4;
	n4.next = &n6;
	n6.next = &n9;
	
	ListNode *p = NULL;
	p = Merge(&n1,&n2);
	while(p!= NULL)
	{
		cout<<p->val<<"	";
		p = p->next;
	}
	cout<<endl;
	return 0;
}

