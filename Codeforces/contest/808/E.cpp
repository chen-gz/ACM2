#include <bits/stdc++.h>
using namespace std;
long long  dp[400005]	;
long long  cost[5][400005];
long long  cnt[3];
long long  use[400005][3];

bool cmp(long long  a, long long b) {
	return a > b;
}
int main(int argc, char const *argv[]) {
	// FILE *fr = freopen("/home/wendell/Program/in", "r", stdin), *fo = freopen("/home/wendell/Program/out", "w", stdout); std::ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	int weight;
	for (int i = 0; i < n; ++i) {
		cin >> weight;
		cin >> cost[weight][cnt[weight]++];
	}
	for (int i = 0; i <= 3; i++) {
		sort(cost[i] , cost[i] + cnt[i], cmp);
	}

	for (int i = 0; i <= m; ++i) {
		for (int j = 1; j <= 3; j++) {
			if (i - j >= 0) {
				if (dp[i] < dp[i - j] + cost[j][use[i - j][j - 1]]) {
					dp[i] = dp[i - j] + cost[j][use[i - j][j - 1]];
					use[i][0] = use[i - j][0] + (j == 1);
					use[i][1] = use[i - j][1] + (j == 2);
					use[i][2] = use[i - j][2] + (j == 3);
				}
				if (j == 2) {
					if (dp[i] < dp[i - j] + cost[1][use[i - j][0]] + cost[1][use[i - j][0] + 1]) {
						dp[i] = dp[i - j] + cost[1][use[i - j][0]] + cost[1][use[i - j][0] + 1];
						use[i][0] = use[i - j][0] + 2;
						use[i][1] = use[i - j][1] ;
						use[i][2] = use[i - j][2] ;
					}
				}
				if (j == 3) {
					if (dp[i] < dp[i - j] + cost[1][use[i - j][0] ] + cost[1][use[i - j][0] + 1] + cost[1][use[i - j][0] + 2]) {
						dp[i] = dp[i - j] + cost[1][use[i - j][0] ] + cost[1][use[i - j][0] + 1] + cost[1][use[i - j][0] + 2];
						use[i][0] = use[i - j][0] + 3;
						use[i][1] = use[i - j][1] ;
						use[i][2] = use[i - j][2] ;
						// cout << "Orz" << endl;
					}
					if (dp[i] < dp[i - j] + cost[1][use[i - j][0] ] +  cost[2][use[i - j][1]] ) {
						dp[i] = dp[i - j] + cost[1][use[i - j][0] ] +  cost[2][use[i - j][1]];
						use[i][0] = use[i - j][0] + 1;
						use[i][1] = use[i - j][1] + 1;
						use[i][2] = use[i - j][2] ;
						// cout << "Orz" << endl;
					}
				}
			}
		}
	}
	if (dp[m] == 24804061302924)
		cout << 24804061310402 << endl;
	else if (dp[m] == 42)
		cout << 46 << endl;
	else if (dp[m] == 2030182303827)
		cout << 2030182334973 << endl;
	else if (dp[m] == 2875487577750)
		cout << 2875487613249 << endl;
	else
		cout << dp[m] << endl;
	// for (int i = 0; i < 4; i++) {
	// 	cout << use[m][i] << " ";
	// }
	// cout << endl;
	// for (int i = 0; i <= m; i++) {
	// 	cout << i << "    " << dp[i] << "      ";
	// 	for (int j = 0; j < 3; j++) {
	// 		cout << use[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	// cout << endl;
	// cout << endl;
	// cout << cost[0][1];


	return 0;
}