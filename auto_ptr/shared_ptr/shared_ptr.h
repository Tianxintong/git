#ifndef _SHARED_PTR_H
#define _SHARED_PTR_H
#include"./shared_count.h"
template<class Y>
class shared_ptr
{
private:
 	Y* px;
	shared_count pn;
public:
	shared_ptr(Y* p = 0):px(p),pn(p)
	{
		cout<<"create shared_ptr"<<endl;
	}
	~shared_ptr()
	{
		cout<<"free shared_ptr"<<endl;
	}

};
#endif
