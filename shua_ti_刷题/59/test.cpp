#include<iostream>
using namespace std;

template<typename T>
class CQueue
{
		public:
				CQueue(void);
				~CQueue(void);
				void appendTail(const T& node);
				T deleteTail();
		private:
				stack<T> stack1;
				stack<T> stack2;
};
		template<typename T>
void CQueue::appendTail(const T& node)
{
		stack1.push(node);
}
T CQueue::deleteTail()
{
		T tmp;
		if(stack2.empty())
		{
				if(stack1.empty)
						return tmp;
				while(!stack1.empty())
				{
						tmp = stack1.top();
						stack2.push(tmp);
						stack1.pop();
				}
		}
		tmp = stack2.top();
		stack2.pop();
		return tmp;
}
int main()
{

		return 0;
}
