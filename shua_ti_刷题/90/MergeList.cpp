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
class Solution 
{
		public:
				ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
				{
					if(pHead1 == NULL)
					return pHead1;
					if(pHead2 == NULL)
					return pHead2;
					ListNode * p1,*p2,*n1,*n2,*f1,*f2;
					p1 = pHead1;
					p2 = pHead2;
					f1 = pHead1;
					f2 = pHead2;
					ListNode * head = NULL;
					if(pHead1->val < pHead2->val)
					head = pHead1;
					else
					head = pHead2;

					while(p1 && p2)
					{
						while(p2 && p1->val >= p2->val)
						{
							f2 = p2;
							p2 = p2->next;
							f2->next = p1;
						}
						while(p1 && p1->val < p2->val)
						{
							f1 = p1;
							p1 = p1->next;
							f1->next = p2;
						}
					}
					return head;
					
				}
};
