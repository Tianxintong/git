#include<iostream>
#include<string.h>
using namespace std;
#define MAX 10000

typedef struct Node
{
	int data;
	Node *next;
}Node;
void output(Node* head,int pos)
{
	Node *p = head;
	for(;p->next;p=p->next)
	{
		cout<<p->data<<"  ";
	}
}
void Mul(char *a,char *b,int pos)
{
	char *ap = a;
	char *bp = b;
	Node *head = 0;
	 head = new Node;
	head->data = 0;
	head->next = NULL;
	Node *p, *q = head,*p1;
	int temp = 0,temp1,bbit;
	while(*bp)
	{
		p = p->next;
		p1 = q;
		bbit = *bp - 48;
		while(*ap || temp)
		{
			if(!p)
			{
				p = new Node;
				p->data = 0;
				p->next = NULL;
				p1->next = p;
			}
			if(*ap == 0)
			temp1 = temp;
			else
			{
				temp1 = (p1->data)+(*ap-48)*bbit+temp;
				++ap;
				p1->data = temp1%10;
				temp = temp1/10;
				p1 = p;
				p = p->next;
			}
			ap = a;
			++bp;
			q=q->next;
		}
		p = head;
		output(p,pos);
		cout<<endl;
		while(head)
		{
			p = head->next;
			delete head;
			head = p;
		}
	}
}
char* strrev(char *s,int n)
{
	int i = 0,j=n-1;
	for(;i<j;++i,--j)
	{
		char c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	return s;
}
int main()
{
	cout<<"input two numbers: "<<endl;
	char test1[MAX],test2[MAX],*p;
	int pos = 0;
	cin.getline(test1,MAX,'\n');
	cin.getline(test2,MAX,'\n');
	if(p = strchr(test1,'.'))
	{
		pos += strlen(test1)-(p-test2)-1;
		do
		{
			p++;
			*(p-1) = *p;
		}while(*p);
	}
	if(p = strchr(test2,'.'))
	{
		pos += strlen(test2) - (p-test2)-1;
		do
		{
			p++;
			*(p-1) = *p;
		}while(*p);
	}
	Mul(strrev(test1,strlen(test1)),strrev(test2,strlen(test2)),pos);

	return 0;
}
