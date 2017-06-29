#include <bits/stdc++.h>
using namespace std;
const int N  = 200005;
int ac[N];
int a[N];
int sum[N];
int main(int argc, char const *argv[]) {
	// FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	//       *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int n, k, q;
	cin >> n  >> k >> q;
	int l, r;
	for (int i = 0; i < n; ++i) {
		cin >> l >> r;
		if (l == r) {
			ac[l] ++;
		}
		else {
			a[--l]++;
			a[r]--;
		}
	}
	int cnt = a[0];
	for (int i = 1; i < 200005; ++i) {
		ac[i] += cnt;
		cnt += a[i];

	}
	ac[0] = 0;
	for (int i = 1; i < 200005; i++) {
		if (ac[i] >= k) {
			ac[i] = 1;
		}
		else {
			ac[i] = 0;
		}
	}
	sum[0] = ac[0];
	for (int i = 1; i < 200005; i++) {
		sum[i] = sum[i - 1] + ac[i];
	}
	while (q--) {
		int ll, rr;
		cin >> ll >> rr;
		cout << sum[rr] - sum[ll - 1] << endl;
	}
}