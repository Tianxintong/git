#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void PrintMatrixIncircle(vector<vector<int> > &matrix ,int start, vector<int> &result)
{
	int t1 = matrix[0].size() - 1 - start;
	int t2 = matrix.size() - 1  - start;
	int i,j;

	for(i = start;i<=t1;++i)
	result.push_back(matrix[start][i]);

	for(i = start+1;i<=t2;++i)
	result.push_back(matrix[i][t1]);
	if(t1 != start && t2 !=  start)
	{
		for(i = t1-1;i>=start;--i)
		result.push_back(matrix[t2][i]);

		for(i = t2-1;i>start;--i)
		result.push_back(matrix[i][start]);
	}
}

vector<int> printMatrix(vector<vector<int> > matrix)
{
	vector<int> result;
	if(matrix.size() == 0)
	return result;
	if(matrix[0].size() == 0)
	return  result;

	int start = 0;
	while(matrix.size() > 2*start && matrix[0].size() > 2*start)
	{
		PrintMatrixIncircle( matrix,start,result);
		++start;
	}
}
int main()
{
	vector<vector<int> >vv;
	vector<int> v;
	int i = 0;
	for(i = 1;i<8;++i)
	{
		v.push_back(i);
		if(i%7 == 0)
		{
			vv.push_back(v);
			v.clear();
		}
	}	
	
	vector<int>result = printMatrix(vv);


	return 0;
}
