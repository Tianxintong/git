#include<iostream>
using namespace std;

int main()
{
	char *str[] = {"c++","program","Hello","World"};
	char **str1[] = {str+3,str+2,str+1,str};
	char ***str2 = str1;
	cout<<(**++str2)<<endl;
	cout<<(*--*++str2+3)<<endl;
	cout<<(*str2[-2]+3)<<endl;
	cout<<str2[-1][-1]+1<<endl;
	return 0;
}
