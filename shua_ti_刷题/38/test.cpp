#include<iostream>
#include<vector>


//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

using namespace std;
//optimized code
int find_2(int key,vector< vector<int>  > vec)
{
	int found = 0;
	if(vec.size() == 0 )
	{
		return found;
	}
	int row = 0;
	int column = vec[0].size()-1;
	for(;row <vec.size() && column >=0;)
	{
		if(vec[row][column] == key)
		{
			found =1;
			return found;
		}
		else if(vec[row][column] < key)
		{
			++row;
			if(vec[row].size() < column)
			column = vec[row].size()-1;
		}
		else
		{
			--column;
		}
	}
	return found;

}
int find_1(int *matrix,int rows,int columns,int key)
{
	int found = 0;
	if(matrix == NULL||rows <=0 || columns <=0)
	return found;
	int row = 0;
	int column = columns -1;
	for(;row < rows &&column >= 0;)
	{
		if(matrix[row * rows +column] ==  key)
		{
			found = 1;
			return found;
		}
		else if(matrix[row * rows + column] < key)
			++row;
		else
			--column;
	}
	return found;
}
int find(int *matrix,int x,int y,int key)
{
	if(matrix == NULL)
		return 0;
	int i = x-1;
	int j = 0;
	for(;i>=0;--i)
	{
		if(matrix[j*x+i] == key)
		{
			return 1;
		}
		else if(matrix[j*x+i] < key)
		{
			break;
		}
		cout<<matrix[j*x+i]<<endl;;
	}
	for(;j<y && i >= 0;++j)
	{
		if(matrix[j*x+i] == key)
		{
			return 1;
		}
		else if(matrix[j*x+i] > key)
		{
			--i;
		}
		else 
			cout<<matrix[j*x+i]<<endl;;
	}
	return 0;
}
int main()
{
	int arr[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	int x;
	cin>>x;
	cout<<"Result = "<<find(&arr[0][0],4,4,x)<<endl;
	return 0;
}

/*
int find(int (*a)[4],int x,int y,int key)
{
	int i = --x;
	int j = 0;
	for(;i>=0;--i)
	{
		if(a[j][i] == key)
		{
			return 1;
		}
		else if(a[j][i] < key)
		{
			break;
		}
		cout<<a[j][i]<<"  ";
	}

	cout<<"i = "<<i<<endl;
	
	for(;j<y && i >= 0;++j)
	{
		if(a[j][i] == key)
		{
			cout<<"j = "<<j<<endl;
			return 1;
		}
		else if(a[j][i] > key)
		{
			--i;
		}
		cout<<a[j][i]<<"  ";
	}

	return 0;
}

int main()
{	
	int arr[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	int x;
	cin>>x;
//	int *a[4] = &arr[0];
	cout<<"Result = "<<find(&arr[0],4,4,x)<<endl;
	return 0;
}

*/
