#include<iostream>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;

int main()
{

		int n;
		char * arr = NULL;
		size_t len;
		int ret = getline(&arr,&len,stdin);
		cout<<arr<<endl;

		vector<string> data;

		char *saveptr = NULL;
		char *token = strtok_r(arr," ",&saveptr);
		data.push_back(token);

		while(NULL !=(token = strtok_r(NULL," ",&saveptr)))
		{
				data.push_back(token);
				cout<<token<<"	";
		}

		vector<int> vec;

		int num_data = data.size();
		for(int i =0;i<num_data;++i)
		{
				int str_len = data[i].length();
				bool  is_negative = false;
				int t = 0;
				int j = 0;
				while(j<str_len)
				{
						if(data[i][0] == '-')
						{
								is_negative = true;
								++j;
								continue;
						}
						t = t*10 + data[i][j] - '0';
						++j;
				}
				if(is_negative)
				t = -1 *t;
				vec.push_back(t);
				cout<<t<<"	";
		}


		return 0;

}


/*
   for(int i =0;i<len;++i)
   {
   int tmp = 0;
   while(i<len && arr[i] <= '9' &&arr[i] >='0')
   {
   tmp = tmp*10 + arr[i] - '0';
   ++i;
   }
   data.push_back(tmp);
   cout<<tmp<<"	";
   }
   cout<<endl;
   return 0;
   }


 */
