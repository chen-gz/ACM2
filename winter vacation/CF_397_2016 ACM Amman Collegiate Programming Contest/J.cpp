#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
int sum[512][MAXN];
template <class T>
inline void Scan(T &ret)
{
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    ret = c - '0';
    while (c = getchar(), c >= '0' && c <= '9')
        ret = ret * 10 + (c - '0');
}

int main()
{
    int T;
    Scan(T);
    while (T--)
    {
        int n, q, x, s;
        Scan(n); Scan(q);
        ///memset(sum,0,sizeof(sum));  加上超时！！！
        for (int i = 1; i <= n; i++)
        {
            s = 0;
            Scan(x);
            for (int j = 2; j <= 10; j++)
                if (x % j == 0) s = s | (1 << (j - 2));
            for (int j = 0; j < 512; j++)
                sum[j][i] = sum[j][i - 1] + ((s & j) ? 1 : 0);
        }
        while (q--)
        {
            int l, r;
            Scan(l); Scan(r); Scan(x);
            if (x & 1) printf("%d\n", r - l + 1);
            else    printf("%d\n", sum[x >> 1][r] - sum[x >> 1][l - 1]);
        }
    }
    return 0;
}