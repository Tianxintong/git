#include<iostream>

using namespace std;

int main()
{
  int n;
  cin>>n;
 long  int a[n];
  int i =0;
  for(;i<n;++i)
   	cin>>a[i]; 
  int q;
 	cin>>q;
  int b[q];
  for(i = 0;i<q;++i)
    cin>>b[i];
 long int sum[n] = {0};
  sum[0] = a[0];
  for(i = 1;i<n;++i)
  {
     sum[i]=sum[i-1]+a[i];
  }
  for(int i = 0;i<q;++i)
  {
  int j;
   for(j =0;j<n;++j)
   {
    	if(b[i]<=sum[j])
        {
         	cout<<j+1<<endl; 
          break;
        }
   }
  }
 return 0; 
}
