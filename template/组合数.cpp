//http ://blog.csdn.net/acdreamers/article/details/8037918
//直接调用Lucas函数;//板有错;
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef long long LL;
LL n, m, mod; //mod要定义在外面
LL quick_mod(LL a, LL b) {
	LL ans = 1;
	a %= mod;
	while (b) {
		if (b & 1) {
			ans = ans * a % mod;
			b--;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return ans;
}

LL C(LL n, LL m) {
	//求组合数
	if (m > n) return 0;
	LL ans = 1;
	for (int i = 1; i <= m; i++) {
		LL a = (n + i - m) % mod;
		LL b = i % mod;
		ans = ans * (a * quick_mod(b, mod - 2) % mod) % mod;
	}
	return ans;
}

LL Lucas(LL n, LL m) {

	if (m == 0)
		return 1;
	return C(n % mod, m % mod) * Lucas(n / mod, m / mod) % mod;
}
/*
   int main()
   {
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%I64d%I64d%I64d", &n, &m, &mod);
        printf("%I64d\n", Lucas(n+m,m));
    }
    return 0;
   }
 */

//小组合数
#define MAXN 205
int num[MAXN + 1][MAXN + 1];
void get_C(int n, int c)//求<=n的组合数，模c
{
	for (int i = 0; i <= n; i++)
	{
		num[i][i] = 1;
		num[i][0] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			num[i][j] = (num[i - 1][j] + num[i - 1][j - 1]) % c;
		}
	}
}
