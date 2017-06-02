#ifndef _SHARED_COUNT_H
#define _SHARED_COUNT_H
#include"./sp_counted_base.h"
#include"./sp_counted_impl.h"
#include"./sp_counted_impl_yy.h"
class shared_count
{
private:
	sp_counted_base * pi_;
public:
/*
	template<class Y>
	shared_count(Y* p = 0):pi_(new sp_counted_impl<Y>(p))
	{
		cout<<"create shared_count"<<endl;
	}
	*/
	template<class Y>
	shared_count(Y *p = 0)
	{
		cout<<"create shared_count"<<endl;
		#ifdef SP_COUNTED_IMPL_YY
		pi_ = new sp_counted_impl_yy<Y>(p);
		#elif SP_COUNTED_IMPL
		pi_= new sp_counted_impl<Y>(p);
		#endif
	}
/*	shared_count():pi_(0)
	{
		cout<<"create shared_count"<<endl;	
	}*/
	~shared_count()
	{
		cout<<"free shared_count"<<endl;
		if(pi_!=0)
		{
			pi_->release();
		}
	}
};
#endif
