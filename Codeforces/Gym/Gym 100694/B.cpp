#include <bits/stdc++.h>
using namespace std;
int main() {
    int p, n, x;
    while (~scanf("%d%d%d", &p, &n, &x)) {
        int ans = x;
        ans = min(ans, x / p + x % p);
        ans = min(ans, x / p * p + p - x + x / p + 1);
        int t1 = n / p + (n % p == 0 ? 0 : 1);
        ans = min(ans, t1 + n - x);
        ans = min(ans, t1 + (n - x) / p + (n - (n - x) / p * p - x));
        int t2 = (n - x) / p + ((n - x) % p == 0 ? 0 : 1);
        ans = min(ans, t1 + t2 + x - (n - t2 * p));
        printf("%d\n", ans);
    }
    return 0;
}