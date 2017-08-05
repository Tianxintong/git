#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h> 

int main()
{
	printf("Content-Type:text/html\n\n");
	printf("<html>");
	printf("<title>register Result</title>");
	printf("<body>");
	printf("<H1 align=center>register result.</H1>");
	char * data = getenv("QUERY_STRING");
	if(data == NULL)
	{
		printf("<p>erro! the QUERY_STRING get fail.<br>");
	}
	else
	printf("<p>the data %s<br>",data);
	/*
	MYSQL my_connection;
	int res;
	mysql_init(&my_connection);

	 if (mysql_real_connect(&my_connection, "localhost", "root", "123456","bg_opt",0,NULL,CLIENT_FOUND_ROWS))
	{
		printf("<p>mysql Connection success <br>");
                res = mysql_query(&my_connection, "insert into bg values('anny','3333','123@qq.com')");
	if(!res)
	{
		 printf("Inserted %lu rows\n",(unsigned long)mysql_affected_rows(&my_connection));
	}
	else
	{
		fprintf(stderr, "Insert error %d: %s\n",mysql_errno(&my_connection),mysql_error(&my_connection));
	}
	mysql_close(&my_connection);
	}
	else
	{
		 fprintf(stderr, "Connection failed\n");

                  if (mysql_errno(&my_connection))
		{
			 fprintf(stderr, "Connection error %d: %s\n",mysql_errno(&my_connection),mysql_error(&my_connection));
		}
	}
*/
	printf("</body>");
	printf("</html>");
}
