#include<stack>
#include<vector>
#include<iostream>
using namespace  std;



struct ListNode
{
		int val;
		struct ListNode *next;
		ListNode(int x) :val(x), next(NULL) 
		{   }
};
class Solution {
		public:

				ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
				{
						if(pListHead == NULL)
						return NULL;
						ListNode * p = pListHead;
						ListNode *back = NULL;
						int i = 0;
						while(i != k)
						{
							p = p->next;
							++i;
						}
						back = pListHead;
						if(p == NULL && i== k)//!!
						return pListHead;
						else if(p == NULL)//!!
						return NULL;
						while( p != NULL)
						{
							p = p->next;
							back = back->next;
						}
					cout<<back->val<<endl;
					return back;
				}
};

int main()
{
		ListNode node1(1);
		ListNode node2(2);
		node2.next = &node1;
		ListNode node3(3);
		node3.next = &node2;
		ListNode node4(4);
		node4.next = &node3;
		ListNode node5(5);
		node5.next = &node4;
		ListNode node6(6);
		node6.next = &node5;
		ListNode node7(7);
		node7.next = &node6;
		ListNode node8(8);
		node8.next = &node7;
		Solution a;
		a.FindKthToTail( &node8,5);
		return 0;
}
