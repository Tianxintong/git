#include<iostream>
#include<stack>
using namespace std;

class Solution
{
		public:
				void push(int value) 
				{
					st1.push(value);
					if(st2.size() == 0 || st2.top()>value)
					st2.push(value);
					else
					st2.push(st2.top());
				}
				void pop() 
				{
					st1.pop();
					st2.pop();
				}
				int top() 
				{
					return st1.top();
				}
				int min() 
				{
					if(st1.size() >0 && st1.size() > 0)
					return st2.top();
				}
		private:
				stack<int> st1;
				stack<int> st2;
};

int main()
{
	Solution s;
	s.push(3);
	s.push(5);
	s.push(7);
	cout<<"s.min= "<<s.min()<<endl;
	s.push(8);
	s.push(1);
	s.push(77);
	s.push(3);
	cout<<"s.min= "<<s.min()<<endl;
	s.pop();
	s.pop();
	s.pop();

	cout<<"s.min= "<<s.min()<<endl;
	return 0;
}
