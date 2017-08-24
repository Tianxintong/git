#include<vector>
#include<iostream>
#include<stack>
using namespace std;
struct ListNode
{
		int val;
		struct ListNode* next;
ListNode(int x) :val(x), next(NULL) 
{
		}
};

vector<int> printListFromTailToHead(ListNode* head) 
{
		stack<ListNode*> nodes;
		ListNode* tmp = head;
		while(tmp)
		{
				nodes.push(tmp);
				tmp = tmp->next;
		}
		while(!nodes.empty())
		{
				cout<<nodes.top()->val<<"	";
				nodes.pop();
		}
		vector<int> t;
		return t;

}
int main()
{
	
		ListNode node1(1);
		ListNode node2(2);
		ListNode node3(3);
		ListNode node4(4);
		node1.next = &node2;
		node2.next = &node3;
		node3.next = &node4;
		printListFromTailToHead(&node1);
		return 0;
}
/*
   struct ListNode
   {
   int m_nKey;
   ListNode* m_pNext;
   }


   vector<int> printListFromTailToHead(ListNode* head) 
   {
   deque<int> vec;
   ListNode *tmp = head;
   while(tmp)
   {
   vec.push_front(tmp->val);
   tmp = tmp->next;
   }
   deque<int>::iterator it = vec.begin();
   while(it != vec.end())
   {
   cout<<*it<<"	";
   ++it;
   }
   return vector<int> tmp;
   }


   void PrintListFromTailToHead(ListNode * pHead)
   {
   std::stack<ListNode*> nodes;
   ListNode* tmp = nodes;
   while(tmp)
   {
   nodes.push(tmp);
   tmp = tmp->m_pNext;
   }
   while(!nodes.empty())
   {
   cout<<nodes.top()->m_nKey<<"	";
   nodes.pop();
   }
   }
 */

