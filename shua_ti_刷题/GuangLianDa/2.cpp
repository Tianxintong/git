/*
题目描述：给定一个字符串，求出其所有可能的字符组合．
比如：abc 其所有组合是:a,b,c,ab,ac,bc,abc

是递归的思想：首先你拿到的是abc，你可以依次打印出去掉c,b,a的组合：ab,ac,bc
然后递归用这些子串去调动这个函数，比如ab:依次去掉b,a打印出a,b;
ac依次打印出a,c;bc依次打印出b,c;但是存在一个问题打印重复了，这个
可以传进去一个参数pos来解决
*/


#include<iostream>

using namespace std;
void fun(string str,int pos)
{
	if(str.length() == 0)
	return;
		for(int i = pos - 1; i >=0; --i)
		{
			string tmp;
			for(int j = 0;j<str.length();++j)
			{
				if(j != i)
				{
					tmp += str[j];
				}
			}
			fun(tmp,i);
		}
		cout<<str<<" ";
}
int main()
{
	string str("abcd");
	fun(str,4);
	cout<<endl;
	return  0;
}
