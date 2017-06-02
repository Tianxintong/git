#ifndef _SP_COUNTED_IMPL_H
#define _SP_COUNTED_IMPL_H
#include"./sp_counted_base.h"
template<class X>
class sp_counted_impl_yy:public sp_counted_base
{
private:
	X* px_;
public:
	sp_counted_impl_yy(X *px):px_(px)
	{
		cout<<"create sp_counted_impl_yy"<<endl;
	}
	~sp_counted_impl_yy()
	{
		cout<<"free sp_counted_impli_yy"<<endl;
	}
	virtual void dispose()
	{
		delete px_;
		delete this;
	}

};

#endif
