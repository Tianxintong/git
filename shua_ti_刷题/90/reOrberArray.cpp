#include<algorithm>
#include<iterator>
#include<iostream>
#include<vector>
using namespace std;

void reOrderArray(vector<int> &array)
{
	vector<int> even;
	vector<int> odd;
	vector<int>::iterator it = array.begin();
	
	for(;it != array.end();++it)
	{
		if(*it & 1)
		odd.push_back(*it);
		else
		even.push_back(*it);
	}

	array.clear();

	it = odd.begin();
	for(;it != odd.end();++it)
	array.push_back(*it);
	
	it = even.begin();
	for(;it != even.end();++it)
	array.push_back(*it);

}
int main()
{
	vector<int> array;
//	array.push_back(1);
	/*
	array.push_back(2);
	array.push_back(3);
	array.push_back(4);
	array.push_back(5);
	array.push_back(6);
	array.push_back(7);
	array.push_back(8);
	array.push_back(9);
	array.push_back(10);
	*/
	reOrderArray(array);
	copy(array.begin(),array.end(),ostream_iterator<int>(cout,"\n"));
	return 0;
}
