#include<stdio.h>
#include <sys\stat.h>
#include<stdlib.h>

#if 1
void transform1(char **r,char **w);
void transform2(char **r,char **w);
void transform3(char **r,char **w);
void transform4(char **r,char **w);

int main()
{
	FILE *read=fopen("C:\\Users\\jhon\\Desktop\\测试.c","rb");
	FILE *write=fopen("C:\\Users\\jhon\\Desktop\\测试后的文件.c","wb");
		struct _stat buf;
	char *p1,*p2,*p3;
	int size;
	_stat("C:\\Users\\jhon\\Desktop\\测试.c",&buf);
	size = buf.st_size;
	p1=(char *)malloc(size+1);
	p2=(char *)malloc(2*size+1);
	memset(p1,0,size+1);
	memset(p2,0,size*2+1);
	p3=p2;
	fread(p1,size,1,read);
	printf("%s",p1);
	transform4(&p1,&p2);

	p3=realloc(p3,strlen(p3)+1);

	printf("%s",p3);
	fwrite(p3,strlen(p3)+1,1,write);
	fclose(read);
	fclose(write);
	return 0;
}
void transform4(char **p1,char **p2)
{
	while(**p1!='\0')
	{
		if(**p1=='"')
		{
			transform1(p1,p2);
		}
		else if(**p1=='/')
		{
			if(*(++(*p1))=='/')
				transform2(p1,p2);
			else if(**p1=='*')
				transform3(p1,p2);
			else
			{
				--(*p1);
				*((*p2))=**p1;
				++(*p1);
				*(++(*p2))=**p1;
				++(*p1);
			}
		}
		else 
		{
			*(++(*p2))=**p1;
			++(*p1);
		
		}
	}
}
//   --"------
void transform1(char **p1,char **p2)
{
	*(++(*p2))='"';
	++(*p1);
	do
	{
		if(**p1 == '\\' && *(++(*p1)) == '\"')
		{
			*(++(*p2)) = '\\';
			*(++(*p2)) = '\"';
			++(*p1);
		}

		else
		{
	
			++(*p2);
			**p2=**p1;
			++(*p1);
		}
		
			
	}while(**p1!='"');
	*(++(*p2))='"';
	++(*p1);
	
}
//    --//--
void transform2( char **p1,char **p2)
{
	**p2='/';
	++(*p2);
	**p2='*';
	++(*p2);

	while(**p1!= '\n')
	{
		if(**p1 == '/')
		{
			if(*(++(*p1)) =='*'||**p1 == '/')
			{
				++(*p1);
		        **p2 = ' ';
		        *(++(*p2))= ' ';
		     }
		}
	     
		else if(**p1 == '*'&&*(++(*p1)) == '/')
		{
			
				++(*p1);
				**p2 =' ';
				*(++(*p2)) = ' ';
			
		}
		else if(**p1=='"')
			transform1(p1,p2);
		else
		{
			**p2 = **p1;
			++(*p2);
			++(*p1);
		}
	}
		--(*p2);
		**p2='*';
		++(*p2);
		**p2='/';
//		*(++(*p2))='\n';
	//	++(*p2);


}
//--    /*  -----------

void transform3(char **p1,char **p2)
{
	*(++(*p2))='/';
	*(++(*p2))='*';
	++(*p1);

	while(**p1!='*')
	{
		if(**p1=='/')
		{
			if(*(++(*p1))=='*'||**p1=='/')
			{
				*(++(*p2))=' ';
				*(++(*p2))=' ';
				++(*p1);
			}
			else
			{
				*(++(*p2))='/';
				*(++(*p2))=**p1;
				++(*p1);
			}
		}
		else if(**p1=='"')
			transform1(p1,p2);
		else
s:		{
		
			*(++(*p2))=**p1;
			++(*p1);
		}
	}
	if(*(++(*p1))=='/')
	{
		--(*p1);
		*(++(*p2))=**p1;
		++(*p1);
		*(++(*p2))=**p1;
	}
	else 
	{
		*(++(*p2))='*';
		goto s;
	}

}

			
#endif






/*	while((a = fgetc(p)) != EOF)
	{
		if(a=='/'&&((a = fgetc(r))=='/'))
		{
				a='/';
			fputc(a,w);
			a='*';
			fputc(a,w);
			while((a=fgetc(r)!='\r'&&a!=EOF)
			{
				if(a=='/'&&(a=getc(r))=='/'||a=='/'&&(a=getc(r))=='*')
				{
					a=' ';
					fput(a,w);
				}
				else if(a=='*"&&((a=fgetc(r))=='/')
				{
					a=' ';
					fput(a,w);
				}
			}
			else if(
	}
	fclose(p);
	fclose(p1);

*/	
#if 0
void transform1(char **p1,char **p2);
int main()
{
	char a[50]="\"/*abcd*8**ef//123/*\"123*/";
	char b[50]=" ";
	char *p1=a;
	char *p2=b;
	puts(a);
	printf("\n");
	transform1(&p1,&p2);
	puts(b);
	return 0;
}
void transform1(char **p1,char **p2)
{
	*(++(*p2))='\"';
	do
	{
			++(*p1);
			++(*p2);
			**p2=**p1;

		
	}while(**p1!='\"');
	//	transform4(p1,p2);
}
#endif