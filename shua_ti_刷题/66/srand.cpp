#include<stdlib.h>

#include<iostream>

#include<unistd.h>
#include<time.h>

using namespace std;

int main()
{
	time_t t;
	srand((unsigned int)time(&t));
	for(int i = 0;i<10;++i)
	{
		cout<<rand()%(100-60+1)+60<<endl;
		sleep(1);
	}
	return 0;
}
