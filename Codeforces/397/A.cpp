#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 1.5e4 + 8;
int a[158], b[158];
LL da[maxn], db[maxn], l, r, ans;
const LL MOD = 1e9 + 7;

inline LL mod(const LL &x) {
	return x - x / MOD * MOD;
}

int main() {
	int T, n, m, k, w, i, j;
	cin >> T;
	while (T--) {
		memset(da, 0, sizeof da);
		memset(db, 0, sizeof db);
		cin >> n >> m >> k >> w;
		if ((w + k) & 1) {
			l = (w - k) / 2 + 1, r  = (w + k) / 2;
		}
		else {
			l = (w - k) / 2, r  = (w + k) / 2;
		}

		for (i = 0; i < n; i++) {
			cin >> a[i];
		}

		da[0] = 1;
		for (i = 0; i < n; i++) {
			for (j = w; j >= 0; j--) {
				if (j - a[i] >= 0)
					da[j] = mod(da[j] + da[j - a[i]]);
				else
					break;
			}
		}

		for (i = 0; i < m; i++) {
			cin >> b[i];
		}
		db[0] = 1;
		for (i = 0; i < m; i++) {
			for (j = w; j >= 0; j--) {
				if (j - b[i] >= 0)
					db[j] = mod(db[j] + db[j - b[i]]);
				else break;
			}
		}

		ans = 0;
		for (i = l; i <= r; i++) {
			// cout << da[i] << " " << db[i] << endl;
			ans = mod(ans + mod(da[i] * db[w - i]));
		}
		cout << ans << endl;
	}
	return 0;
}
