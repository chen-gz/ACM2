//
// Created by wendell on 2/20/19.
//
#include <iostream>
#include <string>

#define  N int(1e5+10)
#define MOD int(1e9+7)
typedef long long ll;
using namespace std;

int find(char c) {
	if (c <= 'Z')
		return c - 'A' + 26;
	return c - 'a';
}

ll poww(ll base, ll exp, ll mod) {
	ll ans = 1;
	while (exp) {
		if (exp & 1)
			ans = ans * base % mod;
		base = base * base % mod;
		exp >>= 1;
	}
	return ans;
}

ll dp[N];
int cnt[52];
ll factorial[N];
ll ans[52][52];

int main() {
	ios::sync_with_stdio(false);
	string str;
	cin >> str;
	int n = str.length();
	for (int i = 0; i < n; i++)
		cnt[find(str[i])]++;
	factorial[0] = 1;
	for (int i = 1; i < N; i++)
		factorial[i] = factorial[i - 1] * i %MOD;
	ll W = poww(factorial[n / 2], 2, MOD);
	for (int i = 0; i < N; i++)
		factorial[i] = poww(factorial[i], MOD - 2, MOD);
	for (int i = 0; i < 52; i++)
		W = W * factorial[cnt[i]] % MOD;
	dp[0] = 1;
	for (int i = 0; i < 52; i++) {
		if (cnt[i] == 0)
			continue;
		for (int j = N - 1; j >= cnt[i]; j--)
			dp[j] = (dp[j] + dp[j - cnt[i]]) % MOD;
	}
	for (int i = 0; i < 52; i++) {
		ans[i][i] = dp[n / 2];
	}
	for (int i = 0; i < 52; i++) {
		if (cnt[i] == 0)
			continue;
		for (int j = cnt[i]; j < N; j++) {
			dp[j] = (dp[j] - dp[j - cnt[i]] + MOD) % MOD;
		}
		for (int j = i + 1; j < 52; j++) {
			if (cnt[j] == 0)
				continue;
			for (int k = cnt[j]; k < N; k++)
				dp[k] = (dp[k] - dp[k - cnt[j]] + MOD) % MOD;
			ans[j][i] = ans[i][j] = dp[n / 2] * 2;
			for (int k = N - 1; k >= cnt[j]; k--)
				dp[k] = (dp[k] + dp[k - cnt[j]]) % MOD;
		}
		for (int k = N - 1; k >= cnt[i]; k--)
			dp[k] = (dp[k] + dp[k - cnt[i]]) % MOD;
	}
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << ans[find(str[x-1])][find(str[y-1])] * W % MOD << endl;
	}
	return 0;
}

