#include<stdio.h>
#include<stdlib.h>
#include<deque>
#include<iostream>
#include<vector>
using namespace std;
#include"./bigint.h"
int main()
{
	printf("Content-Type:text/html\n\n");
	printf("<html>");
	printf("<tile>BigInt Opt </tile>");
	printf("<body>");
	printf("<H1 align=center>Welcome to BigInt Opt</H1>");
	char *data;
	char  b1[100], b2[100];
	int opt;
	data = getenv("QUERY_STRING");
	if(data == NULL)
	printf("<p>erro! the data input fail.<br>");
	else 
	{
		sscanf(data,"opt=%d&b1=%[^&]&b2=%s",&opt,b1,b2);
		printf("<p>data = %20s<br>",data);
		printf("<p>opt = %d<br>",opt);
		printf("<p>b1 = %s<br>",b1);
		printf("<p>b2 = %s<br>",b2);
	}
	
	BigInt bg(0);
	BigInt bg1(0);
	BigInt bg2(0);
	bg1.clear();
	bg2.clear();

	char tm = '+';

	int j = 0;
	if(b1[0] == '-')
	{
		j = 1;
	}

	while(b1[j] != '\0')
	{
		bg1.push_front(b1[j]-'0');
		++j;
	}

	if(b1[0] == '-')
	bg1.push_front(b1[0]);
	else 
	bg1.push_front(tm);

	j = 0;
	if(b2[0] =='-')
	{
		j = 1;
	}
	while(b2[j] != '\0')
	{
		bg2.push_front(b2[j]-'0');
		++j;
	}
	if(b2[0] == '-')
	bg2.push_front(b2[0]);
	else
	bg2.push_front(tm);

	switch(opt)
	{
		case 1:
		BigInt::Add(bg,bg1,bg2);
		break;
		case 2:
		BigInt::Sub(bg,bg1,bg2);
		break;
		default:
		break;
	}
	char *res = new char[bg.size()+1];
	int i = bg.size()-1;
	deque<u_char>::iterator it = bg.begin();
	res[0] = *bg.begin();
	++it;	
	while(it != bg.end())
	{
		res[i] = *it+'0';
		++it;
		--i;
	}
	res[bg.size()] = '\0';
	printf("<p>the result =%s<br>",res);
	printf("</body>");
	printf("</html>");
//	delete res[];
	
	return 0;
}
