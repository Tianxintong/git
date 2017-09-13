#include<iostream>
#include<vector>
using namespace std;

//找出一个给定字符串中dji的所有组合方案　　比如：ddiadjijdi 结果是6
//主要利用了string 的assign  length  find  函数
//遍历字符串找j找到后在j的左边去找d的个数，在右边去找i的个数，找到后num_d*num_i，这样直到所有的j都找完，吧所有的加起来

int main()
{
		int n;
		cin>>n;
		vector<string> vec;
		for(int i = 0;i<n;++i)
		{
				string tmp;
				cin>>tmp;
				vec.push_back(tmp);
		}
		int num_j = 0;
		int num_d = 0;
		int num_i = 0;
		int result = 0;
		for(int i =0;i<n;++i)
		{
				string tmp = vec[i];
				string left;
				string right;
				int pos_j = 0;
				while(pos_j < tmp.length())
				{
						int left_end;
						pos_j = tmp.find('j',pos_j);
						if(pos_j >=0)
						{
								left.assign(tmp,0,pos_j);
								right.assign(tmp,pos_j+1,tmp.length());
								cout<<"j  left :"<<left<<endl;
								cout<<"j right :"<<right<<endl;
								++pos_j;

								int pos_d = 0;
								while(pos_d < left.length())
								{
										pos_d = left.find('d',pos_d);
										if(pos_d>=0)
											num_d++;
										else
										break;
										++pos_d;
								}

								int pos_i = 0;
								while(pos_i < right.length())
								{	
										pos_i = right.find('i',pos_i);
										if(pos_i >= 0)
											num_i++;
										else 
										break;
										++pos_i;
								}

								cout<<"num_d = "<<num_d<<"	"<<"num_i = "<<num_i<<endl;
								result += num_i*num_d;
								num_d = 0;
								num_i = 0;
						}
						else
						break;

				}
		}
		cout<<"result = "<<result<<endl;
		return 0;
}
