#include<iostream>

using namespace std;


struct ListNode 
{
		int val;
		struct ListNode *next;
		ListNode(int x) :
				val(x), next(NULL) 
		{}
};
class Solution {
		public:
				ListNode* ReverseList(ListNode* pHead) 
				{
					if( NULL == pHead)
					return NULL;
					if(NULL == pHead->next)
						return pHead;
					if(pHead->next->next == NULL)
					{
						ListNode *tmp = pHead->next;
						tmp->next = pHead;
						pHead->next = NULL;
						return tmp;
					}
					ListNode *next,front,p;
					p = pHead;
					next = pHead->next;
					while(next && next->next)
					{
						front = p;
						p = next;
						next = next->next;
						p->next = front;
					}
					next->next = p;
					pHead->next = NULL;
					return next;
				}
};
