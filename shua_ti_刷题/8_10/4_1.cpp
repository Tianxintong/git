#include<iostream>
#include<stack>
using namespace std;
stack<wchar_t> ret;
void fun(int n)
{
		if(n<0)
				cout<<"负";
		int t = n;
		int i = 0;
		int len = 0;
		int str[11];
		while(t)
		{
				str[i++] = t%10;
				t=t/10;
				++len;
		}
		for(i = len -1;i >= 0; --i)
		{
				if(str[i] == 0)
				{
						cout<<"零";
						continue;
				}

				switch(str[i])
				{
						case 1:
								cout<<"一";
								break;
						case 2:
								cout<<"二";
								break;
						case 3:
								cout<<"三";
								break;
						case 4:
								cout<<"四";
								break;
						case 5:
								cout<<"五";
								break;
						case 6:
								cout<<"六";
								break;
						case 7:
								cout<<"七";
								break;
						case 8:
								cout<<"八";
								break;
						case 9:
								cout<<"九";
								break;
				}	
				switch(i%4)
				{
						case 1:
								cout<<"十";
								break;
						case 2:
								cout<<"百";
								break;
						case 3:
								cout<<"千";
								break;
				}
				if(i == 4)
				{
						cout<<"万";
				}
				if(i==8)
				{
						cout<<"亿";
				}

		}
		cout<<endl;
}
int main()
{
		cout<<"sizeof(wchar_t) = "<<sizeof(wchar_t)<<endl;	
		int n = 1234560789;
		cout<<n<<endl;
		fun(n);
		return 0;
}
