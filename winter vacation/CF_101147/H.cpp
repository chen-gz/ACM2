#include <bits/stdc++.h>
int mapn[12][12][12];
int dp[12][12][12];
using namespace std;
int main(int argc, char const *argv[]) {
	freopen("commandos.in", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) {
		memset(mapn, 0, sizeof(mapn));
		memset(dp, 0, sizeof(dp));
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int F, X, Y;
			scanf("%d%d%d", &F, &Y, &X);
			scanf("%d", &mapn[F][Y][X]);
		}
		for (int i = 10; i > 0; i--) {
			for (int j = 1; j < 11; j++) {
				for (int k = 1; k < 11; k++) {
					dp[i][j][k] = max(dp[i + 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1])) + mapn[i][j][k];
				}
			}
		}
		printf("%d\n", dp[1][10][10]);
	}
	return 0;
}