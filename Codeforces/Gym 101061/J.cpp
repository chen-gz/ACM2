#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ull bot[100005], mmax[100005];

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	int n, m, a, b;
	ll ans;
	while (T--) {
		memset(bot, 0, sizeof(bot));
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> mmax[i];
		while (m--) {
			cin >> a >> b;
			bot[a] += b;
		}
		for (int i = 1; i <= n; i++) {
			if (bot[i] > mmax[i]) {
				bot[i + 1] += bot[i] - mmax[i];
				bot[i] = mmax[i];
			}
		}
		cout << bot[n + 1] << endl;
		for (int i = 1; i < n; i++) cout << bot[i] << ' ';
		cout << bot[n] << endl;
	}
	return 0;
}
