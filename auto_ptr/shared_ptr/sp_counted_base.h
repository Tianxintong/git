#ifndef _SP_COUNTED_BASE_H
#define _SP_COUNTED_BASE_H

#include<iostream>
using namespace std;
#include"./config.h"
class sp_counted_base
{
private:
	int use_count_;
public:
	sp_counted_base():use_count_(1)
	{
		cout<<"create sp_counted_base"<<endl;
	}
	~sp_counted_base()
	{
		cout<<"free sp_counted_base"<<endl;
	}
	virtual void dispose() = 0;
	void release()
	{
		if(--use_count_==0)
		this->dispose();
	}
};
#endif
