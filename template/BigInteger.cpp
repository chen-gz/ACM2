/*前提：没有前导0*/
#include <cstdio>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct BigInteger
{
	static const int BASE = 100000000;
	static const int WIDTH = 8;
	vector<int>s;
	bool pos_neg;
	
	BigInteger(long long num = 0)
	{
		*this = num;
		pos_neg = 1;
	}
	BigInteger operator = (long long num)
	{
		s.clear();
		if(num < 0)
		{
			this->pos_neg = 0;
			num = -num;
		}
		do
		{
			s.push_back(num % BASE);
			num /= BASE;
		}while(num > 0);
		return *this;
	}
	BigInteger operator = (const string& str)
	{
		s.clear();
		int x,len = (str.length() - 1) / WIDTH + 1;
		for(int i = 0;i < len;i ++)
		{
			int end = str.length() - i*WIDTH;
			int start = max(0,end - WIDTH);
			sscanf(str.substr(start,end - start).c_str(),"%d",&x);
			s.push_back(x);
		}
		return *this;
	}
	bool operator < (const BigInteger& b) const
	{
		if(this->pos_neg == 1 && b.pos_neg == 1)
		{
			if(s.size() != b.s.size())
				return s.size() < b.s.size();
			for(int i = s.size()-1;i >= 0;i --)
				if(s[i] != b.s[i])
					return s[i] < b.s[i];
			return 0;
		}
		else if(this->pos_neg == 0 && b.pos_neg == 0)
		{
			if(s.size() != b.s.size())
				return s.size() > b.s.size();
			for(int i = s.size()-1;i >= 0;i --)
				if(s[i] != b.s[i])
					return s[i] > b.s[i];
			return 0;
		}
		else if(this->pos_neg == 0 && b.pos_neg == 1)
			return 1;
		else if(this->pos_neg == 1 && b.pos_neg == 0)
			return 0;
	}
	bool operator > (const BigInteger& b) const
	{
		return b < *this;
	}
	bool operator <= (const BigInteger& b) const
	{
		return !(b < *this);
	}
	bool operator >= (const BigInteger& b) const
	{
		return !(*this < b);
	}
	bool operator != (const BigInteger& b) const
	{
		return b < *this || *this < b;
	}
	bool operator == (const BigInteger& b) const
	{
		return !(b < *this) && !(b > *this);
	}
	
	friend ostream& operator << (ostream &out,const BigInteger& x)
	{
		if(x.pos_neg == 0)
			out << '-';
		out << x.s.back();
		for(int i = x.s.size() - 2;i >= 0;i --)
		{
			char buf[20];
			sprintf(buf,"%08d",x.s[i]);
			for(int j = 0;j < strlen(buf);j ++)
				out << buf[j];
		}
		return out;
	}
	friend istream& operator >> (istream &in,BigInteger& x)
	{
		string s;
		if(!(in >> s))
			return in;
		if(s[0] == '-')
		{
			if(s[1] != '0')
			{
				x.pos_neg = 0;
				s = s.substr(1);			
			}
		}
		x = s;
		return in;
	}
	
	BigInteger operator - (void)
	{
		BigInteger c;
		c = *this;
		if(*this != 0)
		{
			if(pos_neg == 0)
				c.pos_neg = 1;
			else
				c.pos_neg = 0;
		}
		return c;
	}
	BigInteger operator + (const BigInteger& b) const
	{
		BigInteger c;
		c.s.clear();
		if(this->pos_neg == 1 && b.pos_neg == 1)
		{
			c.pos_neg = 1;
			for(int i = 0,g = 0; ; i ++)
			{
				if(g == 0 && i >= s.size() && i >= b.s.size())
					break;
				int x = g;
				if(i < s.size())
					x += s[i];
				if(i < b.s.size())
					x += b.s[i];
				c.s.push_back(x % BASE);
				g = x / BASE;
			}
			return c;
		}
		else if(this->pos_neg == 0 && b.pos_neg == 0)
		{
			c.pos_neg = 0;
			for(int i = 0,g = 0; ; i ++)
			{
				if(g == 0 && i >= s.size() && i >= b.s.size())
					break;
				int x = g;
				if(i < s.size())
					x += s[i];
				if(i < b.s.size())
					x += b.s[i];
				c.s.push_back(x % BASE);
				g = x / BASE;
			}
			return c;
		}
		else
		{
			BigInteger t1 = *this,t2 = b;
			if(t1 == -t2)
			{
				c = 0;
				return c;
			}
			if(t1 < 0)
			{
				BigInteger tem = t1;
				t1 = t2;
				t2 = tem;
			}
			if(t1 > -t2)
			{
				t2 = -t2;
				c.pos_neg = 1;
				for(int i = 0,g = 0; ; i ++)
				{
					if(g == 0 && i >= t1.s.size() && i >= t2.s.size())
						break;
					if(g == 1)
					{
						t1.s[i] --;
						g = 0;
					}
					if(t1.s[i] < 0)
					{
						t1.s[i] += BASE;
						g = 1;
					}
					int x;
					if(i >= t2.s.size())
						x = t1.s[i];
					else
					{
						if(t1.s[i] < t2.s[i])
						{
							t1.s[i] += BASE;
							g = 1;
						}
						x = t1.s[i] - t2.s[i];
					}
					if(x != 0 || (x == 0 && i < t1.s.size()-1))
						c.s.push_back(x);
				}
				for(int i = c.s.size()-1; ;i --)
				{
					if(c.s[i] == 0)
					{
						c.s.pop_back();
					}
					else
						break;
				}
				return c;
			}
			else
			{
				t2 = -t2;
				c.pos_neg = 0;
				for(int i = 0,g = 0; ; i ++)
				{
					if(g == 0 && i >= t1.s.size() && i >= t2.s.size())
						break;
					if(g == 1)
					{
						t2.s[i] --;
						g = 0;
					}
					if(t2.s[i] < 0)
					{
						t2.s[i] += BASE;
						g = 1;
					}
					int x;
					if(i >= t1.s.size())
						x = t2.s[i];
					else
					{
						if(t2.s[i] < t1.s[i])
						{
							t2.s[i] += BASE;
							g = 1;
						}
						x = t2.s[i] - t1.s[i];
					}
					if(x != 0 || (x == 0 && i < t2.s.size()-1))
						c.s.push_back(x);
				}
				for(int i = c.s.size()-1; ;i --)
				{
					if(c.s[i] == 0)
					{
						c.s.pop_back();
					}
					else
						break;
				}
				return c;
			}
		}
	}
	BigInteger operator - (const BigInteger& b)
	{
		BigInteger t = b;
		return *this + (-t);
	}
	BigInteger operator += (const BigInteger& b)
	{
		*this = *this + b;
		return *this;
	}
	BigInteger operator -= (const BigInteger& b)
	{
		*this = *this - b;
		return *this;
	}
	BigInteger& operator ++()
	{
		*this += 1;
		return *this;
	}
	BigInteger& operator --()
	{
		*this -= 1;
		return *this;
	}
	const BigInteger operator ++(int)
	{
		BigInteger tem = *this;
		*this += 1;
		return tem;
	}
	const BigInteger operator --(int)
	{
		BigInteger tem = *this;
		*this -= 1;
		return *this;
	}
	BigInteger operator * (const BigInteger& b)
	{
		BigInteger c;
		c.s.clear();
		for(int i = 0;i < b.s.size();i ++)
		{
			BigInteger tem;
			tem.s.clear();
			for(int j = 0;j < i;j ++)
			{
				tem.s.push_back(0);
			}
			long long g = 0;
			for(int j = 0; ;j ++)
			{
				if(g == 0 && j >= s.size())
					break;
				long long x = g;
				if(j < s.size())
					x += (long long)b.s[i] * (long long)s[j];
				tem.s.push_back(x % BASE);
				g = x / BASE;
			}
			c += tem;
		}
		c.pos_neg = !(pos_neg ^ b.pos_neg);
		return c;
	}
	BigInteger operator *= (const BigInteger& b)
	{
		*this = *this * b;
		return *this;
	}
	BigInteger operator / (const BigInteger& b)
	{
		BigInteger c;
		c.s.clear();
		if(b > *this)
			return 0;
		else if(b == 1 || b == -1)
			return *this;
		BigInteger mem = 1,temb = b;
		while(temb * mem * 10 <= *this)
		{
			mem *= 10;
		}
		BigInteger tem = *this;
		while(mem != 0)
		{
			if(temb * mem <= tem)
			{
				tem -= temb * mem;
				c += mem;
			}
			else
			{
				int i = mem.s.size() - 1;
				mem.s[i] /= 10;
				if(mem.s[i] == 0)
				{
					mem.s.pop_back();
					if(mem.s.size() == 0)
						break;
					else
					{
						i --;
						mem.s[i] = BASE / 10;
					}
				}
			}
		}
		c.pos_neg = !(pos_neg ^ b.pos_neg);
		return c;
	}
	BigInteger operator /= (const BigInteger& b)
	{
		*this = *this / b;
		return *this;
	}
	BigInteger operator % (const BigInteger& b)
	{
		BigInteger c;
		c.s.clear();
		BigInteger tem = *this,temb = b;
		if(tem < 0)
			tem = -tem;
		if(temb < 0)
			temb = -temb;
		tem /= temb;
		tem *= temb;
		if(*this > 0)
			c = *this - tem;
		else if(*this < 0)
			c = -(*this) - tem;
		if(tem < 0)
			c = -c;
		return c;
	}
	BigInteger operator %= (const BigInteger& b)
	{
		*this = *this % b;
		return *this;
	}
};