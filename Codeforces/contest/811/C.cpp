#include <bits/stdc++.h>
using namespace std;
int border[50005][2];
int a[50005];
int dp[50005];
bool have[50005];
int main(int argc, char const *argv[]) {
	FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	      *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int  n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!have[a[i]]) {
			border[a[i]][0] = i;
			have[a[i]] = true;
		}
		border[a[i]][1] = i;
	}
	for (int i = 0; i < n; ++i) {
		memset(have, false, sizeof(have));
		if (i > 0)
			dp[i] = dp[i - 1];
		int beg = border[a[i]][0];
		int end = border[a[i]][1];
		int ac = 0;
		if (border[a[i]][1] == i) {
			for (int j = i; j >= 0; j--) {
				beg = min(border[a[j]][0], beg);
				end = max(border[a[j]][1], end);
				if (end != i)
					break;
				if (!have[a[j]]) {
					ac ^= a[j];
					have[a[j]] = true;
				}
				if (j == beg ) {
					if (j - 1 >= 0)
						dp[i] = max(dp[j - 1] + ac, dp[i]);
					else
						dp[i] = max(ac, dp[i]);
				}

			}
		}

	}
	// for (int i = 0; i < n; i++)
	// 	cout << dp[i ] << " ";
	cout << dp[n - 1] << endl;
	return 0;
}