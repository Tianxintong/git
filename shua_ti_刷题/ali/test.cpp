#include<iostream>
#include<set>
using namespace std;
/*

给定一个字符串S和有效单词的字典D，请确定可以插入到S中的最小空格数，使得最终的字符串完全由D中的有效单词组成，并输出解。
如果没有解则应该输出n/a
例如
输入
S = "ilikealibaba"
D = ["i", "like", "ali", "liba", "baba", "alibaba"]
Example Output:
输出
"i like alibaba"
解释：
字符串S可能被字典D这样拆分
"i like ali baba"
"i like alibaba"
很显然，第二个查分结果是空格数最少的解。


编译器版本: gcc 4.8.4
请使用标准输入输出(stdin，stdout) ；请把所有程序写在一个文件里，勿使用已禁用图形、文件、网络、系统相关的头文件和操作，如sys/stat.h , unistd.h , curl/curl.h , process.h
时间限制: 3S (C/C++以外的语言为: 5 S)   内存限制: 128M (C/C++以外的语言为: 640 M)
输入:
第一行为字符串S 第二行为输入一个整数表示字典中字符串的个数 其余行为字典中的内容
输出:
输出为加入空格后的字符串
输入范例:
*/
void mincut(const string& str, const set<string>& dict)
{
}


int main(int argc, const char * argv[])
{
		string strS;
		string dictStr;
		int nDict;
		set<string> dict;

		cin>>strS;
		cin>>nDict;
		for (int i = 0; i < nDict; i++)
		{
				cin>>dictStr;
				dict.insert(dictStr);
		}
		mincut(strS, dict);

		return 0;
}
