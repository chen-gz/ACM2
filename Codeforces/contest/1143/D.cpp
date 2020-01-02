#include <algorithm>
#include <bits/stdc++.h>
#define N (long long)(1e15 + 1)
using namespace std;
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main() {
    ios::sync_with_stdio(false);
    // FILE *file = freopen("../input", "r", stdin);
    long long n, k;
    cin >> n >> k;
    long long a, b;
    cin >> a >> b;
    long long mmin = N, mmax = -1;
    vector<long long> ac;
    ac.push_back(a + b);
    ac.push_back(a - b);
    ac.push_back(-a + b);
    ac.push_back(-a - b);
    for (long long i = 0; i < 4; i++) {
        while (ac[i] < 0)
            ac[i] += n * k;
    }
    for (long long i = 0; i <= n; i++) {
        for (long long j = 0; j < 4; j++) {
            mmin = min(mmin, n * k / gcd(n * k, i * k + ac[j]));
            mmax = max(mmax, n * k / gcd(n * k, i * k + ac[j]));
        }
    }
    cout << mmin << " " << mmax << endl;
    return 0;
}
