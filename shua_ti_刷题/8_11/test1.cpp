#include<iostream>

using namespace std;
int func(int n)
{
	int t = n;
	int ret[10] ={0};
	int count = 0;
	int tag;
	for(int i=2;i<10;)
	{
		t = n;
		tag = n;
		for(int j =i;j<10;++j)
		{
			if(t <= 9 && t>=0)
			{
				ret[count] = ret[count]*10+ t;
				break;
			}

			while(t%j ==0)
			{
				ret[count] = ret[count]*10 + j;
				t /= j;
			}

			if( t == 1)
			break;
			if(j == 9 && t == tag)
			return -1;
			if(j == 9 && t != 1 )
			{
				j = 1;
				tag = t;
			}
		}
		++count;
		t = n;
		++i;
		while(t%i != 0)
		++i;
	}
	int min = ret[0];
	cout<<ret[0]<<"  ";
	for(int i =1;i<count;++i)
	{
	cout<<ret[i]<<"  ";
		if(ret[i] < min)
		min = ret[i];
	}
	cout<<endl;
	return min;
}
int main()
{
	int n;
	cin>>n;
	cout<<func(n)<<endl;
	return 0;
}
