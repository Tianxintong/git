#include<stdio.h>

int main()
{
	char c;
	int i = 0;
	while(i = scanf("%c",&c))
	{
		if(c == '\n')
		break;
		printf("%c",c);

	}
	return 0;
}
