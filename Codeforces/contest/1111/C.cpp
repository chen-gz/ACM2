#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
long long n, k, A, B;
long long calc(long long  l, long long  r) {
    long long  index_small = lower_bound(a.begin(), a.end(), l) - a.begin();
    long long  index_large = upper_bound(a.begin(), a.end(), r) - a.begin();
    index_large --;
    long long  num = index_large - index_small +1 ;
    long long ans = 0;
    if (num == 0)
        ans = A;
    else
        ans = B * (r - l + 1) * num;
    if (l != r && num != 0) {
        long long mid = (l + r) / 2;
        ans = min(ans, calc(l, mid) + calc(mid + 1, r));
    }
    return ans;
}
int main() {
    FILE *file = freopen("../input", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> A >> B;

    long long tmp;
    for (int i = 0; i < k; i++) {
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    long long r = (long long)1 << n;
    cout << calc(1, r);
    return 0;
}
