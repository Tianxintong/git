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
	{	
		u_char sym  = *begin();
		*begin() = a;
		bi.push_front(sym);
	}
	void  push_front_cgi(u_char a)
	{
		bi.push_front(a);
	}
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
	{
		if(size() == 2)
		return;
		if(bi.back() == 0) 
		bi.pop_back();
	}
	static BigInt& Abs(const BigInt &bt,BigInt &tmp)
	{
		tmp = bt;
		tmp.pop_front();
		tmp.SetSymbol(POSITIVE);
		return tmp;
	}
/////////////////////////////////////////
	static u_char AddItem(u_char a,u_char b,u_char &sign);
	static u_char SubItem(u_char a,u_char b,u_char &sign);
	static void MulItem(BigInt &b, const BigInt &b1,u_char x);
	static void AddMove(BigInt &b, const BigInt &b1,int offset);
	static void  Add(BigInt &b,const  BigInt &b1,const  BigInt &b2);
	static void Sub(BigInt &b, const BigInt &b1, const BigInt &b2);
	static void Mul(BigInt &bt,const BigInt &b1,const BigInt &b2);
	static void Div(BigInt &bt,const BigInt &b1,const BigInt &b2);
	static void Mod(BigInt &bt,const BigInt &b1,const BigInt &b2);//bt = bt1 % bt2
	static void Squate(BigInt &bt,const BigInt &bt1);//bt = bt1^2
	static void Power(BigInt &bt,const BigInt &bt1,u_char n);//bt = bt1^n
	static void Power(BigInt &bt,const BigInt &bt1,const BigInt &bt2);//bt = bt1^bt2
	static void PowMod(BigInt &bt,const BigInt &bt1,const BigInt &bt2,const BigInt &bt3);//bt = bt1^bt2%bt3
////////////////////////////////////////
	bool operator<(const BigInt &b)const;
	bool operator>=(const BigInt &b)const;
	bool operator>(const BigInt &b)const;
	bool operator<=(const BigInt &b)const;
	bool operator==(const BigInt &b)const;
	bool operator!=(const BigInt &b)const;

	BigInt& operator++();
	BigInt  operator++(int);
	BigInt& operator--();
	BigInt  operator--(int);
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
		i = strlen((char*)str)-1;
		while(i>0)
		{
			bi.push_back(((*(s+i)-'0')%10));
			--i;
		}
	}
	else
	{
		SetSymbol(POSITIVE);
		bi.push_back(0);
	}
}
////////////////////////////////////////////////////////////////

BigInt& BigInt::operator++()
{
	BigInt tmp(1);
	BigInt t(1);
	BigInt::Add(tmp,(*this),t);
	(*this) = tmp;
	return *this;
}
BigInt BigInt::operator++(int)
{
	BigInt tmp(1);
	tmp = *(this);
	++(*this);
	return tmp;
}
BigInt& BigInt::operator--()
{
	BigInt tmp(1);
	BigInt t(1);
	BigInt::Sub(tmp,(*this),t);
	(*this) = tmp;
	return *this;
}
BigInt BigInt::operator--(int)
{
	BigInt tmp(1);
	tmp = *(this);
	--(*this);
	return tmp;
}
///////////////////////////////////////////////////////////////
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
	BigInt tmp1(0);
	BigInt tmp2(0);

	if((sym1 == '+' && sym2 == '+')||(sym1 == '-' && sym2 == '-'))
	{
		Abs(b1,tmp1);
		Abs(b2,tmp2);
		if(tmp1 > tmp2)
		{
			it1 = tmp1.begin();
			it1_end = tmp1.end();
			it2 = tmp2.begin();
			it2_end = tmp2.end();
		}
		else
		{
			it1 = tmp2.begin();
			it1_end = tmp2.end();
			it2 = tmp1.begin();
			it2_end = tmp1.end();
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
		
		if((sym1 == '+' &&	b1>b2)||(sym1 == '-' && b2 >b1))
		b.SetSymbol(POSITIVE);
		else
		b.SetSymbol(NEGATIVE);
	/*
		b.SetSymbol(sym1);
		if(b1.size() >b2.size() )
		{
			it1 = b1.begin();//it1指向长的数字
			it1_end = b1.end();
			it2 = b2.begin();//it2指向较短的数字
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
	*/	
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
	if(*bt1.begin() == *bt2.begin())
	bt.SetSymbol(POSITIVE);
	else
	bt.SetSymbol(NEGATIVE);
}
void BigInt::Div(BigInt &bt,const BigInt &bt1,const BigInt &bt2)
{
	assert(bt2!=0);
	bt.clear();
	BigInt tmp1(0);
	BigInt tmp2(0);
	u_char sym1 = bt1.GetSymbol();
	u_char sym2 = bt2.GetSymbol();
	size_t len1 = bt1.size();
	size_t len2 = bt2.size();
	int k = len1 - len2;
	Abs(bt1,tmp1);
	Abs(bt2,tmp2);

	if(sym1 == sym2)
	bt.SetSymbol(POSITIVE);
	else
	bt.SetSymbol(NEGATIVE);

	if(tmp1 == tmp2)
	{
		bt.push_back(1);
		return;
	}
	if(tmp1 < tmp2)
	{
		bt.push_back(0);
		bt.pop_front();
		bt.SetSymbol(POSITIVE);
		return;
	}

	BigInt btm;
	btm.clear();
	btm.SetSymbol(POSITIVE);
	u_char div = 0;
	const_iter it = bt1.end();
	
	--it;
	--len2;
	while(len2--)
	{
		btm.push_front(*it);
		--it;
	}
	const_iter t = it;
	++t;
	while(t != bt1.begin())
	{
		if(btm < tmp2)
		{	
			u_char a = 0;
			bt.push_front(a);
			btm.push_front(*it--);
			--t;
			continue;
		}
		while(btm >= tmp2)
		{
			btm -=tmp2;
			++div;
		}
		bt.push_front(div);
		btm.push_front(*it--);
		btm.clear_head_zero();
		--t;
		div = 0;
	}
	btm.pop_front();
//	cout<<"bt1 %  bt2 = ";	
//	btm.show();
	bt.clear_head_zero();
}
void  BigInt::Mod(BigInt &bt,const BigInt &bt1,const BigInt &bt2)
{
	assert(bt2!=0);
	bt.clear();
	BigInt tmp1(0);
	BigInt tmp2(0);
	u_char sym1 = bt1.GetSymbol();
	u_char sym2 = bt2.GetSymbol();
	size_t len1 = bt1.size();
	size_t len2 = bt2.size();
	int k = len1 - len2;
	Abs(bt1,tmp1);
	Abs(bt2,tmp2);

	if(sym1 == sym2)
	bt.SetSymbol(POSITIVE);
	else
	bt.SetSymbol(NEGATIVE);

	if(tmp1 == tmp2)
	{
		bt.push_back(1);
		return;
	}
	if(tmp1 < tmp2)
	{
		bt = tmp1;
		return;
	}

	BigInt btm;
	btm.clear();
	btm.SetSymbol(POSITIVE);
//	u_char div = 0;
	const_iter it = bt1.end();
	
	--it;
	--len2;
	while(len2--)
	{
		btm.push_front(*it);
		--it;
	}
	const_iter t = it;
	++t;
	while(t != bt1.begin())
	{
		if(btm < tmp2)
		{
			btm.push_front(*it--);
			--t;
			continue;
		}
		while(btm >= tmp2)
		{
			btm -=tmp2;
//			++div;
		}
//		bt.push_front(div);
		btm.push_front(*it--);
		--t;
//		div = 0;
	}
	btm.pop_front();
//	cout<<"bt1 %  bt2 = ";	
//	btm.show();
	bt = btm;

}
void BigInt::Squate(BigInt &bt,const BigInt &bt1)
{
	BigInt::Mul(bt,bt1,bt1);
}
void  BigInt::Power(BigInt &bt,const BigInt &bt1,u_char n)//bt = bt1^n
{
	BigInt tmp(1);
	tmp = bt1;
	bt = tmp;
	u_char i = n;
	while(--i)
	{
		BigInt::Mul(tmp,bt1,bt);
		bt = tmp;
	}
}
void BigInt::Power(BigInt &bt,const BigInt &bt1,const BigInt &bt2)
{
	BigInt tmp(0);
	BigInt t(0);
	BigInt p(1);
	bt = p;
	assert(bt2 > t);
	tmp = bt2;

	while(!(tmp.size() == 2 &&tmp[1] == 0))
	{
		BigInt::Mul(p,bt1,bt);
		bt = p;
		--tmp;
	}
	
}

void BigInt::PowMod(BigInt &bt,const BigInt &bt1,const BigInt &bt2,const BigInt &bt3)//bt = bt1^bt2%bt3
{
	BigInt b2(0);
	b2 = bt2;
	BigInt ret(1);
	BigInt bt1_mod_bt3(0);
	BigInt::Mod(bt1_mod_bt3,bt1,bt3);
	BigInt tmp(0);
	while(!( b2.size()==2 &&b2[1] == 0))
	{
		BigInt::Mul(tmp,bt1_mod_bt3,ret);
		BigInt::Mod(ret,tmp,bt3);
		--b2;
	}
	bt = ret;
	BigInt tmp1(2);
	BigInt::Mod(tmp,bt2,tmp1);//tmp = bt2 % 2
	bt.pop_front();
	if((tmp[1] == 0)||bt1.GetSymbol()==POSITIVE)
	bt.SetSymbol(POSITIVE);
	else
	bt.SetSymbol(NEGATIVE);
	
}
