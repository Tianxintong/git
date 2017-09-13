#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;



#include <iostream>
#include <string>
using namespace std;

int main()
{
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		for (int i = 0; i < s2.size(); i++)
		{
				int index;
				while((index=s1.find(s2[i]))!=-1)
				{
						s1.erase(index, 1);
				}
		}
		cout << s1 << endl;
		return 0;
}
/*
   int main()
   {
   char * s1,*s2;
   size_t len;

   int ret = getline(&s1,&len,stdin);
   ret = getline(&s2,&len,stdin);

//	cout<<"s1 = "<<s1<<endl;
//	cout<<"s2 = "<<s2<<endl;

string result;

int flag[59] = {0};
size_t len1 = strlen(s1);
size_t len2 = strlen(s2);
//	cout<<len1<<"	"<<len2<<endl;
for(int i =0;i<len2;++i)
{
flag[s2[i]-'A'] = 1;
}
for(int i = 0;i<len1;++i)
{
//		if(s1[i] <'A' && s1[i]>'Z' && s1[i]<'a' &&s1[i]>'z')
if(s1[i] == ' ')
{
result += s1[i];
continue;
}
if(!flag[s1[i]-'A'])
result += s1[i];
}

//	cout<<"SS	"<<' '-'A'<<endl;
//
int i = 0;
int count = 0;
size_t  len2 = strlen(s2);
int len1 = strlen(s1);
bool not_has = true;
while(i<len1)
{

for(int j = 0;j<len2;++j)
{
if(s1[i] == s2[j])
{
not_has = false;
break;
}
}
if(not_has)
result += s1[i];
not_has = true;
++i;
}

cout<<result<<endl;
free(s1);
free(s2);
return 0;
}

 */
