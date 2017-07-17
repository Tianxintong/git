#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <conio.h>

int  help(int *p[4][4]);
int full_screen(int *p[4][4]);
int game_fail(int *p[4][4]);
void combine(int *p[4][4],int *score,int *count);
void out(int *p[4][4],int *score,int *move);
void Rand(int *p[4][4]);
void downchange(int *p[4][4]);
void rightchange(int *p[4][4]);
int g=0;
int temp[4][4]={0};

void main()
{
	int a[4][4]={0};
	int i,j;
	int *p[4][4];
	int score=0;
	int *s=&score;
	int count;
	int *c=&count;
	int move=0;
	int *m=&move;
	char ch;
	srand((unsigned)time(NULL));
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			p[i][j]=&a[i][j];
	Rand(p);
	Rand(p);
	out(p,s,m);
	while((ch=getch())!='q')
	{
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				temp[i][j]=*p[i][j];
		if(ch=='w')
		{
		combine(p,s,c);

			++(*m);
		}
		else if(ch=='a')
		{
			rightchange(p);
			downchange(p);
			combine(p,s,c);
			downchange(p);
			rightchange(p);
			++(*m);
		}
		else if(ch=='s')
		{
			downchange(p);
			combine(p,s,c);
			downchange(p);
			++(*m);
		}

		else if(ch=='d')
		{
			downchange(p);
			rightchange(p);
			combine(p,s,c);
			rightchange(p);
			downchange(p);
			++(*m);

		}
		else if(ch=='q')
			exit(0);
		if(help(p)==1)
		{
			Rand(p);
		
		}
		else
		{
			--(*m);
		}
		out(p,s,m);
		if(0==game_fail(p))
			exit(0);
		if(1==g)
		{
			printf("you win!!!!\n");
			exit(0);
		}
	}
}


void Rand(int *p[4][4])
{
		int t=0;
		int m=0;
	if(0==full_screen(p))
		return ;

	t = rand()%2;
	m = rand()%16 ;
	t = 2*t +2;
	
	if(*(*(*(p+ m/4) + m%4))==0)
		*(*(*(p+ m/4) + m%4))	= t;
	else
		Rand(p);
}
void combine(int *p[4][4],int *score,int *count)

{
	int i,j,k;
	for(j=0;j<4;j++)
		for(i=0;i<4;i++)
		{
			if(**(*(p+i)+j)!=0)
			{
				for(k=i+1;k<4;k++)
				{
					if(**(*(p+i)+j)==**(*(p+k)+j))
					{
						**(*(p+i)+j)=**(*(p+i)+j)*2;
						*score=**(*(p+i)+j)+*score;
						++(*count);
						**(*(p+k)+j)=0;
						i=k;
						break;
					
					}
					else if(**(*(p+k)+j)==0)
						;
					else
						break;
				}
			}
			
		}		

		for(j=0;j<4;j++)
			for(i=0;i<4;i++)
				if(**(*(p+i)+j)==0)
				{
					for(k=i+1;k<4;k++)
					{
						if(**(*(p+k)+j)!=0)
						{
							*p[i][j]=*p[k][j];
							**(*(p+k)+j)=0;
							break;
						}
					}
				}

}


void downchange(int *p[4][4])
{
	int i,j,*t;
	for(i=0;i<4;i++)
	{
		for(j=0;j<2;j++)
		{
			t=p[j][i];
			p[j][i]=p[4-j-1][i];
			p[4-j-1][i]=t;
		}
	}
}
void rightchange(int *p[4][4])
{
	int i,j,*t;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4-i;j++)
		{
			t=p[j][i];
			p[j][i]=p[4-i-1][4-j-1];
			p[4-i-1][4-j-1]=t ;
		}
	}
}



void out(int *p[4][4],int *score,int *move)
{
	int i,j;
	system("cls");
	printf("2048сно╥\n");
	printf("W-UP  A-LIFT  S-DOWN  D-RIGHT\n");
	printf("score:   %d      move: %d    \n",*score,*move);
	
	for(i=0;i<9;i++)
	{
		if(i == 0)
			printf("|------|------|------|------|\n|      |      |      |      |\n|");
		else if(i==8)
			printf("|------|------|------|------|\n");
		else if(i%2==0)
			printf("|------|------|------|------|\n|      |      |      |      |\n|");
		else
		{
			for(j=0;j<4;j++)
			{
				if(*p[i/2][j]==0)
					printf("      ");
				else
					printf("%6d",*p[i/2][j]);
				printf("|");
			}
			printf("\n");
		}
	}

}

int full_screen(int *p[4][4])
{
	int i,j;
		for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(*p[i][j]==0)
			{
				return 1;
			}
			if(*p[i][j]==2048)
			{
				g=1;
			}
		}
		return 0;
}


int game_fail(int *p[4][4])
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(*p[i][j]==0)
			{
				return 1;
			}
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(*p[i][j]==0)
			{
				return 1;
			}

		for(i=0;i<4;i=i+3)
			for(j=0;j<3;j++)
				if(*p[i][j]==*p[i][j+1])
					return 1;
		for(j=0;j<4;j=j+3)
			for(i=0;i<3;i++)
				if(*p[i][j]==*p[i+1][j])
					return 1;
		for(i=1;i<3;i++)
			for(j=1;j<3;j++)
				if(*p[i][j]==*p[i-1][j]||*p[i][j]==*p[i][j+1]||*p[i][j]==*p[i][j-1]||*p[i][j]==*p[i+1][j])
					return 1;
		return 0;
}
int  help(int *p[4][4])
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(*p[i][j]!=temp[i][j])
				return 1;
	return 0;
}








