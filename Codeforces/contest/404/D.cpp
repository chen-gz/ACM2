#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL mod = 1e9 + 7;
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
int cnt0[200005];
int cnt1[200005];
int allone;
int main()
{
	// FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	//       *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	string str;
	cin >> str;
	if (str[0] == '(') {
		cnt0[0]++;
	}
	else
		cnt1[0]++;
	for (int i = 1; i < str.length(); ++i) {
		if (str[i] == '(') {
			cnt0[i] = cnt0[i - 1] + 1;
			cnt1[i] = cnt1[i - 1];
		}
		else  {
			cnt0[i] = cnt0[i - 1] ;
			cnt1[i] = cnt1[i - 1] + 1;
		}
	}
	int ac = cnt1[str.length() - 1];
	for (int i = 0; i < str.length(); i++) {
		cnt1[i] = ac - cnt1[i] ;
	}
	// for (int i = 0 ; i < str.length(); i++) {
	// 	cout << cnt0[i] << " ";
	// }
	// cout << endl;
	// for (int i = 0; i < str.length(); ++i) {
	// cout << cnt1[i] << " ";
	// }
	// cout << endl;
	long long ans = 0 ;
	// cout << endl;
	for (int i = 0 ; i < str.length(); i++)	{

		if (str[i] == '(') {
			// cout << cnt0[i] << " " << cnt1[i] << " ";
			ans += Lucas(cnt0[i] + cnt1[i] - 1 , cnt0[i]) % mod ;
			ans %= mod;
			// cout << Lucas(cnt0[i] + cnt1[i] - 1 , cnt0[i] ) << endl;
		}
	}
	cout << ans << endl;
	return 0;

}

