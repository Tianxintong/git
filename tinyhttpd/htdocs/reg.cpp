#include<iostream>
#include<stdio.h>
#include<deque>
#include<assert.h>
#include<stdlib.h>
#include<mysql/mysql.h>
#include<string.h>
using namespace std;
#define SERVER_STRING "Server: jdbhttpd/0.1.0\r\n"
int main()
{

	printf("Content-Type:text/html\n\n");

	printf("<html>");
	printf("<head>");
	printf("<title>login</title>");
	printf("</head>");

	printf("<body>");
	printf("<table width=\"100%%\" height=\"100%%\">");
	printf("<tr>");
	printf("<td valign=\"center\" align=\"center\">");
	printf("<form action=\"reg_result.cgi\" method=\"get\">");
	
	printf("<table width=\"500\" align=\"center\" border=\"1\" frame=\"box\" rules=\"all\" cellpadding=\"5\">");
	printf("<caption><h1>Register</h1></caption>");
	
	printf("<tr>");
		printf("<td align=\"right\">username:</td>");
		printf("<td><input type=\"text\" name=\"username\" value=\"\" /> </td>");
	printf("</tr>");
	printf("<tr>");
		printf("<td align=\"right\">password:</td>");
		printf("<td><input type=\"text\" name=\"password\" value=\"\" /> </td>");
	printf("</tr>");
	printf("<tr>");
		printf("<td align=\"right\">e_mail:</td>");
		printf("<td><input type=\"text\" name=\"e_mail\" value=\"\" /> </td>");
	printf("</tr>");

	printf("<tr>");
//		printf("<td colspan=\"2\" align=\"center\" ");
			printf("<input type=\"submit\" value=\"commit\"  />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp ");
			printf("<input type=\"reset\" value=\"reset\"  />");
//		printf("</td>");
	printf("</tr>");
	printf("</table>");
	printf("</form>");
	printf("</td>");
	printf("</tr>");


	printf("</table>");
	printf("</body>");
	printf("</html>");
/*
	MYSQL my_conection;
	int res;
	mysql_init(&my_conection);

	if(mysql_real_connect(&my_conection,"localhost","root","123456","bg_opt",0,NULL,CLIENT_FOUND_ROWS))
	{
		printf("<p>connection success.<br>");
		int res = mysql_query(&my_conection,"insert into bg values(username,password,e_mail)");
		if(!res)
		{
			printf("<p> Insert %lu rows <br>",(unsigned long)mysql_affected_rows(&my_conection));
		}
		else
		{
				printf("<p>Insert Fail.<br>");
	//		printf("<input type=\"reset\" value=\"reset\"  />");
				goto again_input_data;
		}
	}
*/
	return 0;
}
