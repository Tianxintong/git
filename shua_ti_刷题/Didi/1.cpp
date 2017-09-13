#include<iostream>
using namespace std;


int main()
{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0;i<n;++i)
				cin>>a[i];

		int count = 0;
		int tag = 1;

		int front = a[0];
		for(int i = 1;i<n;++i)
		{
				if(front == 0)
				{
						while(i<n)
						{
								if(a[i] == 0)
								{
										++tag;
										++i;
								}
								else
								{
										front = a[i];
										count += tag;
										tag = 1;
										break;
								}
						}
				}
				else
				{
					while(i<n)
					{
						if(front == a[i])
						{
							++tag;
							++i;
						}
						else
						{
							if(tag > 1)
							{
								count += tag/2;
							}
							front = a[i];
							tag = 1;
							break;
						}
					}
				}


		}
		if(a[n-1] == 0)
		count =+ tag;
		else if(tag > 1)
		count = tag/2+count;
		cout<<count<<endl;
		return 0;
}
