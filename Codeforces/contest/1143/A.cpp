#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
long long calc(long long n) {
    int ret = 1;
    while (n > 0) {
        // if (n % 10 != 0)
        ret *= n % 10;
        n /= 10;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    // FILE *file = freopen("../input", "r", stdin);
    long long n;
    cin >> n;
    long long ans = calc(n);
    long long tail = n % 10;
    long long times = 1;
    while (1) {
        ans = max(ans, calc(n - tail - 1));
        tail = n % (long long)pow(10, times);
        if (n - tail <= 0)
            break;
        times++;
    }
    cout << ans << endl;

    return 0;
}
