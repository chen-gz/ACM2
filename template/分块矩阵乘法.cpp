#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int mod;

struct Matrix
{
	long long a[2][2];
	void init()
	{
		memset(a,0,sizeof(a));
		for(int i = 0;i < 2;i ++)
		{
			a[i][i] = 1;
		}
	}
	void mem()
	{
		memset(a,0,sizeof(a));
	}
	void fib()
	{
		memset(a,0,sizeof(a));
		a[0][0] = 1;a[0][1] = 1;a[1][0] = 1;
	}
};

Matrix I,Z,F,A;

struct MM
{
	Matrix M00,M01,M10,M11;
};

Matrix add(Matrix a,Matrix b)
{
	Matrix ans;
	ans.mem();
	for(int i = 0;i < 2;i ++)
	{
		for(int j = 0;j < 2;j ++)
		{
			ans.a[i][j] = a.a[i][j] + b.a[i][j];
			ans.a[i][j] %= mod;
		}
	}
	return ans;
}

Matrix mul(Matrix x,Matrix y)
{
	Matrix ans;
	for(int i = 0;i < 2;i ++)
	{
		for(int j = 0;j < 2;j ++)
		{
			ans.a[i][j] = 0;
			for(int k  = 0;k < 2;k ++)
			{
				ans.a[i][j] += x.a[i][k] * y.a[k][j] % mod;
				ans.a[i][j] %= mod;
			}
		}
	}
	return ans;
}

MM Mmul(MM x,MM y)
{
	MM ans;
	ans.M00 = add(mul(x.M00,y.M00),mul(x.M01,y.M10));
	ans.M01 = add(mul(x.M00,y.M01),mul(x.M01,y.M11));
	ans.M10 = add(mul(x.M10,y.M00),mul(x.M11,y.M10));
	ans.M11 = add(mul(x.M10,y.M01),mul(x.M11,y.M11));
	return ans;
}

Matrix qpow(Matrix x,int n)
{
	Matrix ans;
	ans.init();
	while(n)
	{
		if(n & 1)
		{
			ans = mul(ans,x);
		}
		x = mul(x,x);
		n >>= 1;
	}
	return ans;
}

MM Mqpow(MM x,int n)
{
	MM ans;
	ans.M00.init();
	ans.M01.mem();
	ans.M10.mem();
	ans.M11.init();
	while(n)
	{
		if(n & 1)
			ans = Mmul(ans,x);
		x = Mmul(x,x);
		n >>= 1;
	}
	return ans;
}

int main()
{
	I.init();
	Z.mem();
	F.fib();
	int k,b,n;
	while(scanf("%d%d%d%d",&k,&b,&n,&mod) != EOF)
	{
		MM B,C;
		Matrix Fib,S;
		A = qpow(F,k);
		Fib = qpow(F,b);
		B.M00 = I;B.M01 = I;B.M10 = Z;B.M11 = A;
		C.M00 = I;C.M01 = Z;C.M10 = Fib;C.M11 = Z;
		B = Mqpow(B,n);
		C = Mmul(B,C);
		printf("%d\n",C.M00.a[0][1]%mod);
	}
}