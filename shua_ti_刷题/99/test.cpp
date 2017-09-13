#include<iostream>
using namespace std;
struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};
void DeleteNode(ListNode** pListHead,ListNode *pToDeleted)
{
	if(pListHead == NULL||pToDeleted == NULL)
	return;
	
	if(pToDeleted->m_pNext != NULL)//要删除的节点不是链表的尾部节点
	{
		ListNode *next = pToDeleted->m_pNext;
		pToDeleted->m_nValue = next->m_nValue;
		pToDeleted->m_pNext = next->m_pNext;
		delete next;
		next = NULL;
	}
	else if(pToDeleted ==  *pListHead)//链表中只有一个节点
	{
		delete pToDeleted;
		pToDeleted = *pListHead = NULL;
	}
	else//删除的节点是尾部节点，只能老老实实的从头找到尾部节点的前面一个节点，然后删除该节点
	{
		ListNode* p = *pListHead;
		while(p->m_pNext != pToDeleted)
		{
			p = p->m_pNext;
		}

		p->m_pNext = NULL;
		delete pToDeleted;
		pToDeleted = NULL;
	}
}
int main()
{
	
	return 0;
}
