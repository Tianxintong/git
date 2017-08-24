#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<deque>
using namespace std;
class coordinate
{
public:
	coordinate(){}
	coordinate(int i,int j):x(i),y(j)
	{}
	int operator==(coordinate max)
	{
		return x == max.x && y == max.y;
	}
	int x;
	int y;
};
int is_in_queue(int *tag,int n)
{
	if(tag[n] >0)
	return 1;
	else
	return 0;
}
coordinate max_row(int *sub,int i,int n)
{
	coordinate t;
	int max = *(sub+i*n);
	for(int j = 1;j<n;++j)
	{	
		if(max < *(sub+i*n +j))
		{
			max = *(sub + i*n +j);
			t.x = i;
			t.y = j;
		}
	}
	return t;
}
coordinate max_colunm(int *sub,int i,int n)
{
	coordinate t;
	int max = *(sub + i);
	for(int j = 1;j<n-1;++j)
	{
		if(max < *(sub +j*n+i))
		{
			max = *(sub + j*n +i);
			t.x = j;
			t.y = i;
		}

	}
	return t;
}
coordinate max_sub(int *sub,int n)
{
	coordinate t;
	int max = *sub;
	for(int i = 0;i<n-1;++i)
	{
		for(int j = i+1;j<n;++j)
		{
			if(max < *(sub+i*n+j))
			{
				max = *(sub+i*n+j);
				t.x = i;
				t.y = j;
			}
		}
	}
	return t;
}
void be_zero_row(int *sub,int r,int n)
{
	for(int i = 0;i<n;++i)
	{
		*(sub +(r)*n+i) = 0;
	}
}
void be_zero_colunm(int *sub,int c,int n)
{
	for(int i = 0;i<n;++i)
	{
		*(sub +i*n+c) = 0;
	}
}

void mark_in_queue(int* sub,int *tag,coordinate n,int len)
{
	++tag[n.x];
	++tag[n.y];
	if(tag[n.x] == 2)
	be_zero_row(sub,n.x,len);
	if(tag[n.y] == 2)
	be_zero_colunm(sub,n.y,len);

}

int is_finished(deque<int> &dq,int n)
{
/*
	if(n<0||tag == NULL)
	return 0;
	for(int i = 0;i<n;++i)
	{
		if(tag[i] == 0)
		return 0;
	}
	return 1;
*/	return dq.size() == n ;
}
void show_sub(int *sub,int n)
{
	int i,j;
		for(i = 0;i<n-1;++i)
	{
		int k  =i;
		while(k--)
		{
			cout<<"	";
		}
		for(j = i+1;j<n;++j)
		{
			cout<<*(sub+i*n+j)<<"	";
		}
		cout<<endl<<endl;
	}


}
int main()
{
//	int n = 8;
//	int height[n] = {2,3,5,7,11,13,17,19};
//	int n = 5;
//	int height[n] = {5,10,25,40,25};
	int n;
	cin>>n;
	int height[n];
	for(int i =0;i<n;++i)
	cin>>height[i];
	int sub_len = sizeof(int)*(n)*(n);
	int *  sub = (int*)malloc(sub_len);
	int i,j;
	int crazy = 0;
	
	for(i = 0;i<n-1;++i)
	{
		for(j = i+1;j<n;++j)
		{
			*(sub+i*n+j) = abs(height[i] -height[j]);
		}
	}

	int *tag = (int*)malloc(sizeof(int)*n);
	memset(tag,0,sizeof(int)*n);
	deque<int> dq;
	coordinate max = max_sub(sub,n);
	coordinate max1;
	dq.push_back( max.x );
	dq.push_back(max.y);
	crazy += *(sub+max.x*n+max.y);
	mark_in_queue(sub,tag,max,n);
	*(sub+max.x*n+max.y) = 0;
	
	int front;
	int other,other1;
	int back;
	while(!is_finished(dq,n))
	{
//front extent
		front = dq.front();
		if(front < n/2)
		{
			max = max_row(sub,front,n);
		}
		else

		{
			max = max_colunm(sub,front,n);
		}
		if(max.x == front)
		other = max.y;
		else
		other = max.x;
		
		if(!is_in_queue(tag,other))
		{
			if(other < n/2)
			{
				max1 = max_row(sub,other,n);	
			}
			else
			{
				max1 = max_colunm(sub,other,n);
			}	
			if(max1 == max)
			{
				dq.push_front(other);
				crazy += *(sub+max.x*n+max.y);
			//	cout<<*(sub+max.x*n+max.y)<<"	";
				*(sub+max.x*n+max.y) = 0;
				mark_in_queue(sub,tag,max,n);
			}
			else
			{
					*(sub+max1.x*n+max1.y) = 0;
			}	
		}
		else
			*(sub+max.x*n+max.y) = 0;
//back extent:
		back = dq.back();
		if(back < n/2)
		{
			max = max_row(sub,back,n);
		}
		else

		{
			max = max_colunm(sub,back,n);
		}
		if(max.x == back)
		other = max.y;
		else
		other = max.x;
		
		if(!is_in_queue(tag,other))
		{
			if(other < n/2)
			{
				max1 = max_row(sub,other,n);	
			}
			else
			{
				max1 = max_colunm(sub,other,n);
			}	
			if(max1 == max)
			{
				dq.push_back(other);
			//	cout<<*(sub+max.x*n+max.y)<<"	";
				crazy += *(sub+max.x*n+max.y);
				*(sub+max.x*n+max.y) = 0;
				mark_in_queue(sub,tag,max,n);
			}
			else
			{
				*(sub+max1.x*n+max1.y) = 0;
			}	
		}
		else
		{
			*(sub+max.x*n+max.y) = 0;
		}

	}
	cout<<crazy<<endl;
	deque<int>::iterator it = dq.begin();


	free(sub);
	free(tag);
	return 0;
}
