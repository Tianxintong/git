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
	void SetSymbol(u_char sign);
	void show();	
	size_t  size()const
	{
		return bi.size();
	}
	void push_back(u_char a)
	{
		bi.push_back(a);
	}
	void push_front(u_char a)
	{
		bi.push_front(a);
	}
	void clear()
	{
		bi.clear();
	}
	void pop_front()
	{
		bi.pop_front();
	}
	void pop_back()
	{
		bi.pop_back();
	}
	u_char GetSymbol()const
	{
		return *bi.begin();
	}
	iter begin()
	{
		return bi.begin();
	}
	const_iter begin()const
	{
		return bi.begin();
	}
	
	const_iter end()const
	{
		return bi.end();
	}
	iter end()
	{
		return bi.end();
	}
	u_char operator[](int i)
	{
		return bi[i];
	}
	u_char operator[](int i)const
	{
		return  bi[i];
	}
/////////////////////////////////////////
	static u_char AddItem(u_char a,u_char b,u_char &sign);
	static u_char SubItem(u_char a,u_char b,u_char &sign);
	static void MulItem(BigInt &b,const BigInt &b1,u_char x);
	static void AddMove(BigInt &b,const BigInt &b1,int offset);
	static void  Add(BigInt &b,const BigInt &b1,const BigInt &b2);
	static void Sub(BigInt &b,const BigInt &b1,const BigInt &b2);

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


private:
	deque<u_char> bi;
};
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
 void BigInt::Add(BigInt &b,const BigInt &b1,const BigInt &b2)
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
		//
	}

}

