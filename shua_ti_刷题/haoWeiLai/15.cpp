#include<iostream>

using namespace std;



/*
//最优解法
//依次输入数字，用num和temp来记录当前输入数据中出现最多次数的数字的次数和这个数字,最小空间和最短时间
int main()
{
	int num = 0,temp;
	int cur;
	while(cin>>cur)
	{
		if(num	== 0)
		{
			++num;
			temp = cur;
		}
		else
		{
			if(temp == cur)
			{
				++num;
			}
			else 
			--num;
		}
	}
	cout<<temp<<endl;
	return 0;
}
*/
