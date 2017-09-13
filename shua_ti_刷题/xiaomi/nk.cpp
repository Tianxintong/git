#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;

int main()
{
	vector<string> vec;
	char str[1024];
	char *line = NULL;
	size_t line_len;
	int ret = getline(&line,&line_len,stdin);
//	printf("%s",line);
	
//	cout<<"str len = "<<strlen(line)<<endl;


	char *saveptr = NULL;
	char *token = strtok_r(line," ",&saveptr);
	vec.push_back(token);
//	cout<<token<<"	";
	while(NULL != (token  = strtok_r(NULL," ",&saveptr)))
	{
		vec.push_back(token);
//		cout<<token<<"	";
	}
//	vec.back()[vec.back().length()-1] = '\0';
	vec.back().erase(vec.back().length()-1,vec.back().length());
	int i = vec.size();
	--i;
	while(i >= 0)
	{
		cout<<vec[i];
		if(i != 0)
		cout<<" ";
		--i;
	}
	cout<<endl;
	free(line);
	
	return 0;
}
