#include<istream>

using namespace std;

#define P 7
#define NULL_DATA -1

struct bucket_node
{
	int data[3];
	struct bucket_node* next;
	bucket_node():next(NULL)
	{
		data[0] = NULL_DATA;
		data[1] = NULL_DATA;
		data[2] = NULL_DATA;
	}
};
int insert_new_element(bucket_node *hash_table,int new_element)
{
	int index,i,k;
	bucket_node *s,*front,*t;
	index = new_element%P;
	for( i = 0;i<3;++i)
	{
		if(hash_table[index].data[i] == NULL_DATA)
		{
			hash_table[index].data[i] = new_element;
			break;
		}
	}
	if(i != 3 )
		return 0;
	else
		t = hash_table[index].next;
	while(t != NULL)
	{
		for(k =0;k<3;++k)
		{
			if(t->data[k] == NULL_DATA)
			{
				t->data[k] = new_element;
				break;
			}
		}
		if(k==3)
		{
			front = t;
			t = t->next;
		}
		else
		break;
	}
	if(t == NULL)
	{
		s = new bucket_node;
		if(!s)
		{
			return -1;
		}
		if(hash_table[index].next==NULL)
		hash_table[index].next = s;
		else
		front->next = s;
		s->data[0] = new_element;
	}
	return 0;
}
int main()
{
	bucket_node hash_table[P];
	
	insert_new_element(hash_table,1);
	insert_new_element(hash_table,8);
	insert_new_element(hash_table,15);
	insert_new_element(hash_table,15);
	insert_new_element(hash_table,22);
	insert_new_element(hash_table,2);
	insert_new_element(hash_table,16);
	insert_new_element(hash_table,9);
	insert_new_element(hash_table,9);
	insert_new_element(hash_table,9);
	insert_new_element(hash_table,9);
	insert_new_element(hash_table,9);
	insert_new_element(hash_table,9);
	return 0;
}
