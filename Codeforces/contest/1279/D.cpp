//
// Created by lucas on 12/31/19.
//


#include <bits/stdc++.h>

using namespace std;
#define MOD (long long)998244353

template<typename T>
T mod_pow(T base, T exponent, T module) {
    T ans = 1;
    while (exponent) {
        if (exponent & 1)
            ans = (ans * base) % module;
        base = base * base % module;
        exponent >>= 1;
    }
    return ans;
}

template<typename T>
T mod_mult(T x, T y, T z) {
    return (x * y % MOD) * z % MOD;
}

template<typename T>
T mod_mult(T x, T y) {
    return x * y %MOD;
}

template<typename T>
T mult_inverse(T p) {
    return mod_pow(p, MOD - 2, MOD);
}

template<typename T>
T fraction(T num, T den) {
    return num * mult_inverse(den) % MOD;
}

#define N int(1e6) + 7
map<long long, long long> cnt;

int main() {
    long long n;
    cin >> n;
    vector<long long> v[N];
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        for (int j = 0; j < tmp; j++) {
            long long tmp2;
            cin >> tmp2;
            v[i].push_back(tmp2);
            cnt[tmp2]++;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            ans += fraction(cnt[v[i][j]], mod_mult((long long) v[i].size(), n, n));
            ans %=MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
