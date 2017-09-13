#include<iostream>

using namespace std;


/*思路：假设两个字符串str1和str2，长度分别为m和n，则构建一个m*n的矩阵matrix，

  matrix[i][j]==1表示字符串str1中第i个字符与str2中第j个字符相等，为0则不相等。

  统计矩阵matrix中每条斜线上1的连续最大个数就是str1和str2中公共连续子串的最大长度*/

/*例如：str1: abcde    str2: abgde 

  matrix = [ 1  0  0  0  0 

  0  1  0  0  0

  0  0  0  0  0

  0  0  0  1  0

  0  0  0  0  1 ]

  斜线上连续的1的最大个数为2，所以最长公共连续子串长度为2*/



int main()
{
		char str1[51];
		char str2[51];
		int leng,maxleng = 0;
		cin.getline(str1,51);
		cin.getline(str2,51);
		int matrix[50][50] = {0};

		for(int i = 0;str1[i] != '\0';++i)
		{
				for(int j = 0;str2[j] != '\0';++j)
				{
						if(str1[i] == str2[j])
						{
								matrix[i][j] = 1;
						}
				}
		}
		for(int i = 0;str1[i] != '\0';++i)
		{
				for(int j = 0;str2[j] != '\0';++j)
				{
						leng = 0;
						int m = i;
						int n = j;
						while(matrix[m++][n++] == 1)
						{
								++leng;
						}
						if(maxleng < leng)
								maxleng = leng;
				}
		}
		cout<<maxleng<<endl;
		return 0;
}
/* pass  80%
   int main()
   {
   string a,b;
   getline(cin,a);
   getline(cin,b);
   cout<<a<<"		"<<b<<endl;

   int max_len = 0;
   int len_a = a.length();
   int len_b = b.length();
   int j = 0;
   for(int i = 0;i<len_a;++i)
   {
   if(a[i] == b[j])
   {
   int count = 0;
   while(i<len_a && j<len_b)
   {
   if(a[i] != b[j])
   {
   --j;
   break;
   }
   ++count;
   ++i;
   ++j;
   }
   if(count > max_len)
   max_len = count;
   }

   }

   j = 0;
   for(int i = 0;i<len_b;++i)
   {
   if(b[i] == a[j])
   {
   int count = 0;
   while(i<len_b && j<len_a)
   {
   if(b[i] != a[j])
   {
   --i;
   break;
   }
   ++count;
   ++i;
   ++j;
   }
   if(count > max_len)
   max_len = count;
   }

   }
   cout<<"max_substr len = "<<max_len<<endl;
   return 0;
   }
 */
