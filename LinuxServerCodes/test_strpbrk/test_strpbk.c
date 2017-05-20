#include<string.h>
#include<stdio.h>
int main()
{
    char *str1="pppppease try lagain,llsky2098!";
	    char *str2="Hello,I am sky2098,I like writing!";
		    char *strtemp;
			    strtemp=strpbrk(str1,str2);  //搜索进行匹配
				    printf("Result is:  %s ",strtemp);
					str2 = "lagain";
			    strtemp=strstr(str1,str2);  //搜索进行匹配
				    printf("Result is:  %s ",strtemp);
					    return 0;
						}
