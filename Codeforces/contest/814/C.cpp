#include <bits/stdc++.h>
using namespace std;
int dp[26][2000];
int main(int argc, char const *argv[]) {
	// FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	//       *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	string str;
	cin >> str;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < n; ++j) {
			int fuck  = 0 ;
			for (int k = j; k < n; ++k) {
				if (str[k] - 'a' != i ) {
					fuck++;
				}
				dp[i][fuck] = max(dp[i][fuck], k - j + 1);
			}
		}
		for (int k = 1; k < n; k++) {
			dp[i][k] = max(dp[i][k - 1], dp[i][k]);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int connie; cin >> connie;
		char ch; cin >> ch;
		cout << dp[ch - 'a'][connie] << endl;;
	}
	return 0;
}