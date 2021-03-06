#include<iostream>
#include<bits/stl_function.h>
#include<hash_fun.h>
#include<ext/functional>
#include<hashtable.h>

using namespace std;
using namespace __gnu_cxx;
int  main()
{
	hashtable<int, int, hash<int>, identity<int>, equal_to<int>  >  ht(50, hash<int>(), equal_to<int>());
	cout<<ht.size()<<endl;
	cout<<"max_size()= "<<ht.max_size()<<endl;
	typedef hashtable<int,int, hash<int>, identity<int>, equal_to<int> >::iterator iter;
	ht.insert_unique(54);
	ht.insert_unique(97);
	ht.insert_unique(192);
	ht.insert_unique(52);
	ht.insert_unique(53);
	ht.insert_unique(54);
	ht.insert_unique(3);
	ht.insert_unique(5);
	ht.insert_unique(8);

	iter it = ht.begin();
	while(it!=ht.end())
	{
		cout<<(*it)<<"   ";
		++it;	
	}
	cout<<endl;
	return 0;
}

/*
#include<map>
#include<string>
int main()
{
	map<int ,string> mp;
	mp[0] = "and";
	mp[1] = "string";
	mp[2] = "hello";
	mp[3] = "www";
	typedef map<int,string>::iterator iter ;
	iter it= mp.begin();
	while(it!=mp.end())
	{
		cout<<(*it).second<<"  ";
		++it;
	}
	cout<<endl;

	
}
*/
/*
int main()
{
__gnu_cxx::hashtable<int, int, hash<int>,identity <int>, equal_to<int> >
	          ht(50,__gnu_cxx::hash<int>(), __gnu_cxx::equal_to<int>());
return 0;
}

*/
