#pragma once
typedef unsigned char u_char;
#define POSITIVE '+'
#define NEGATIVE '-'
class BigInt
{
public:
	typedef deque<u_char>::iterator iter;
	typedef deque<u_char>::const_iterator const_iter;

	BigInt(long value = 0);
	BigInt(const BigInt &b);
	BigInt(u_char *str,int len);

	void SetSymbol(u_char sign);
	void show();	
	size_t  size()const
	{return bi.size();}
	void push_back(u_char a)
	{bi.push_back(a);}
	void push_front(u_char a)
	{bi.push_front(a);}
	void clear()
	{bi.clear();}
	void pop_front()
	{bi.pop_front();}
	void pop_back()
	{bi.pop_back();}
	u_char GetSymbol()const
	{return *bi.begin();}
	iter begin()
	{return bi.begin();}
	const_iter begin()const
	{return bi.begin();}
	bool empty()
	{return bi.empty();};
	const_iter end()const
	{return bi.end();}
	iter end()
	{return bi.end();}
	u_char operator[](int i)
	{return bi[i];}
	u_char operator[](int i)const
	{return  bi[i];}
	BigInt& operator=(const BigInt &bt)
	{
		(*this).clear();
		const_iter it = bt.begin();
		while(it != bt.end())
		{
			(*this).push_back(*it);
			++it;
		}
	}
	void clear_head_zero()
	{ if(bi.back() == 0) bi.pop_back();}
/////////////////////////////////////////
	static u_char AddItem(u_char a,u_char b,u_char &sign);
	static u_char SubItem(u_char a,u_char b,u_char &sign);
	static void MulItem(BigInt &b, const BigInt &b1,u_char x);
	static void AddMove(BigInt &b, const BigInt &b1,int offset);
	static void  Add(BigInt &b,const  BigInt &b1,const  BigInt &b2);
	static void Sub(BigInt &b, const BigInt &b1, const BigInt &b2);
	static void Mul(BigInt &bt,const BigInt &b1,const BigInt &b2);
	static void Div(BigInt &bt,const BigInt &b1,const BigInt &b2);
	static void Mod(BigInt &bt,const BigInt &b1,const BigInt &b2);

////////////////////////////////////////
	bool operator<(const BigInt &b)const;
	bool operator>=(const BigInt &b)const;
	bool operator>(const BigInt &b)const;
	bool operator<=(const BigInt &b)const;
	bool operator==(const BigInt &b)const;
	bool operator!=(const BigInt &b)const;

	BigInt& operator++();
	BigInt& operator++(int);
	BigInt& operator--();
	BigInt& operator--(int);
///////////////////////////////////////////////////////
	BigInt& operator-=(const BigInt &b)
	{
		BigInt tmp(0);
		BigInt::Sub(tmp,(*this),b);
		(*this) = tmp;
		return (*this);
	}

////////////////////////////////////////////////////////

private:
	deque<u_char> bi;
};

BigInt::BigInt(const BigInt &b)
{
	const_iter it = b.begin();
	++it;
	while(it != b.end())
	{
		bi.push_back(*it);
		++it;
	}
}
void BigInt::show()
{
	
	iter it = bi.begin();
	cout<<(*it)<<" ";
	++it;
	while(it!=bi.end())
	{
		cout<<(int)(*it)<<"  ";
		++it;
	}
	cout<<endl;
}
void BigInt::SetSymbol(u_char sign)
{
	bi.insert(bi.begin(),sign);
//	*bi.begin() = sign;
}
BigInt::BigInt(long value)
{
	SetSymbol(POSITIVE);
	if(value == 0)
		bi.push_back(0);
	else
	{
		if(value<0)
		{	
			bi.pop_front();	
			SetSymbol(NEGATIVE);
			value = abs(value);
		}
		while(value > 0)
		{
			bi.push_back(value % 10);
			value /= 10;
		}
	}
}
BigInt::BigInt( u_char *str,int len)
{
	u_char *s =str;
	int i = len;
	if(str!=NULL)
	{
		if(*s == '+')
		SetSymbol(POSITIVE);
		else
		SetSymbol(NEGATIVE);
		i = 1;
		while(i<len)
		{
			bi.push_back(((*(s+i)-'0')%10));
			++i;
		}
	}
	else
	{
		SetSymbol(POSITIVE);
		bi.push_back(0);
	}
}
////////////////////////////////////////////////////////////////
bool BigInt::operator<(const BigInt &b)const
{
	if(GetSymbol()=='-'&&b.GetSymbol()== '+')
	return true;
	if(GetSymbol() =='+'&& b.GetSymbol()== '-')
	{
		return false;
	}
	const_iter it1 = end();
	const_iter it2 = b.end();
	if(GetSymbol() == '+')
	{
		if(size()>b.size())
		return false;
		else if(size() < b.size())
		return true;
		else
		{
			--it1;
			--it2;
			while(it1!= begin() && it2 != b.begin())
			{
				if(*it1 >*it2)
					return false;
				else if(*it1 < *it2)
					return true;
				--it1;
				--it2;
			}
			return false;
		}
	}
	else
	{
		if(size() > b.size())
			return true;
		else if(size() < b.size())
			return false;
		else
		{
			--it1;
			--it2;
			while(it1!=begin() && it2 != b.begin())
			{
				if(*it1 >*it2)
					return true;
				else if(*it1 < *it2)
					return false;
				--it1;
				--it2;
			}
			return false;
		}
	}
}
bool BigInt::operator>=(const BigInt &b)const
{
	return !((*this)<b);
}
bool BigInt::operator>(const BigInt &b)const
{

	if(GetSymbol()=='-'&&b.GetSymbol()== '+')
	return  false;
	if(GetSymbol() =='+'&& b.GetSymbol()== '-')
	{
		return true;
	}
	const_iter it1 = end();
	const_iter it2 = b.end();
	if(GetSymbol() == '+')
	{
		if(size()>b.size())
		return true;
		else if(size() < b.size())
		return false;
		else
		{
			--it1;
			--it2;
			while(it1!= begin() && it2 != b.begin())
			{
				if(*it1 >*it2)
					return true;
				else if(*it1 < *it2)
					return false;
				--it1;
				--it2;
			}
			return false;
		}
	}
	else
	{
		if(size() > b.size())
			return false;
		else if(size() < b.size())
			return true;
		else
		{
			--it1;
			--it2;
			while(it1!=begin() && it2 != b.begin())
			{
				if(*it1 >*it2)
					return false;
				else if(*it1 < *it2)
					return true;
				--it1;
				--it2;
			}
			return false;
		}
	}
}
bool BigInt::operator<=(const BigInt &b)const
{
	return !((*this)>b);
}
bool BigInt::operator==(const BigInt &b)const
{
	return bi==b.bi;
}
bool BigInt::operator!=(const BigInt&b)const
{
	return bi!=b.bi;
}
///////////////////////////////////////////////////////////////
u_char BigInt::AddItem(u_char a,u_char b,u_char &sign)
{
	u_char sum = a+b+sign;
	if(sum>= 10)
	{
		sum -= 10;
		sign = 1;
	}
	else
		sign = 0;
	return sum;
}
 void BigInt::Add(BigInt &b,const  BigInt &b1,const  BigInt &b2)
{
	b.bi.clear();
	const_iter  it1 = b1.bi.begin();
	const_iter it2 = b2.bi.begin();
	u_char sym1 = *it1;
	u_char sym2 = *it2;
	++it1;
	++it2;
	u_char sum,sign = 0;
	if((sym1 == '+'&& sym2 == '+')||(sym1 == '-'&&sym2 == '-'))
	{
		b.SetSymbol(sym1);
		while(it1 != b1.bi.end()&&it2 != b2.bi.end())
		{
			sum = AddItem(*it1,*it2,sign);
			b.bi.push_back(sum);
			++it1;
			++it2;
		}
		while(it1 != b1.bi.end())
		{
			sum = AddItem(*it1,0,sign);
			b.bi.push_back(sum);
			++it1;
		}
		while(it2 != b2.bi.end())
		{
			sum = AddItem(0,*it2,sign);
			b.bi.push_back(sum);
			++it2;
		}
		if(sign != 0)
		{
			b.bi.push_back(sign);
		}
	}
	else
	{
		if(b1.size()>b2.size())
		{
			BigInt tmp(b2);
			tmp.SetSymbol(sym1);
			Sub(b,b1,tmp);
		}
		else
		{
			BigInt tmp(b1);
			tmp.SetSymbol(sym2);
			Sub(b,b2,tmp);
		}
	}

}
u_char BigInt::SubItem(u_char a,u_char b,u_char &sign)
{
	u_char sub;
	if(a >= b+sign)
	{
		sub = a - b -sign;
		sign = 0;
	}
	else
	{
		sub = a+10-b-sign;
		sign = 1;
	}
	return sub;
}
void  BigInt::Sub(BigInt &b,const BigInt &b1,const BigInt &b2)
{
	b.clear();
	u_char sym1 = *b1.begin();
	u_char sym2 = *b2.begin();
	const_iter it1,it1_end,it2,it2_end;
	
	u_char sub,sign = 0;

	if((sym1 == '+' && sym2 == '+')||(sym1 == '-' && sym2 == '-'))
	{
		b.SetSymbol(sym1);
		if(b1.size() >b2.size() )
		{
			it1 = b1.begin();
			it1_end = b1.end();
			it2 = b2.begin();
			it2_end = b2.end();
		}
		else
		{
			it1 = b2.begin();
			it1_end = b2.end();
			it2 = b1.begin();
			it2_end = b1.end();
		}	
		++it1;
		++it2;
		while(it2 != it2_end)
		{
			sub = SubItem(*it1,*it2,sign);
			b.push_back(sub);
			++it1;
			++it2;
		}
		while(it1 != it1_end)
		{
			sub = SubItem(*it1,0,sign);
			b.push_back(sub);
			++it1;
		}
		if(sign != 0)
			b.push_back(sign);
		
	}
	else
	{
		if(b1.size()>b2.size())
		{
			BigInt tmp(b2);
			tmp.SetSymbol(sym1);
			Add(b,b1,tmp);
			b.SetSymbol(sym1);
		}
		else
		{
			BigInt tmp(b1);
			tmp.SetSymbol(sym2);
			Add(b,b2,tmp);
			b.SetSymbol(sym1);
		}
	}
	b.clear_head_zero();
}
void BigInt::MulItem(BigInt &bt,const BigInt &bt1,u_char x)
{
	u_char mul,sign = 0;
	const_iter it = bt1.begin();
	++it;
	while(it != bt1.end())
	{
		mul = x *(*it)+sign;
		if( mul > 9)
		{
			sign = mul/10;
			mul %= 10;
		}
		else
		{
			sign = 0;
		}
		bt.push_back(mul);
		++it;
	}
	if(sign != 0)
		bt.push_back(sign);
}
void BigInt::AddMove(BigInt &bt,const BigInt &bt1,int offset)
{
	if(bt.empty())
	{
		bt = bt1;
		return ;
	}
	iter it = bt.begin();
	const_iter it1 = bt1.begin();
	++it;
	++it1;
	
	while(offset--  )
	{
		++it;
		assert(it!=bt.end());
	}
	u_char add,sign;
	while(it != bt.end() && it1 != bt1.end())
	{
		add = AddItem(*it,*it1,sign);
		*it = add;
		++it;
		++it1;
	}
	while(it != bt.end())
	{
		add = AddItem(*it,0,sign);
		*it = add;
		++it;
	}
	while(it1!= bt1.end())
	{
		add = AddItem(*it1,0,sign);
		bt.push_back(add);
		++it1;
	}
	if(sign!=0)
	 bt.push_back(sign);


}
void BigInt::Mul(BigInt &bt,const BigInt &bt1,const  BigInt &bt2)
{
	bt.clear();
	BigInt tmp;
	const_iter it = bt2.begin();
	++it;
	int i = 0;
	for(;it != bt2.end();++it)
	{
		tmp.clear();
		tmp.SetSymbol(POSITIVE);
		MulItem(tmp,bt1,*it);
//		cout<<"bt1 * "<<(int)*it<<endl;
//		tmp.show();
		AddMove(bt,tmp,i++);
	}
	bt.pop_front();
	if(bt1.begin() == bt2.begin())
	bt.SetSymbol(POSITIVE);
	else
	bt.SetSymbol(NEGATIVE);
}
void BigInt::Div(BigInt &bt,const BigInt &bt1,const BigInt &b)
{
}
