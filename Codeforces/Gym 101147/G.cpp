#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1010;
const int MOD = 1e9 + 7;
long long s[MAXN][MAXN];
void init() {
	for (int i = 1; i < MAXN; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (i == j || j == 1) s[i][j] = 1;
			else if (i > 1)
				s[i][j] = (j * s[i - 1][j] % MOD + s[i - 1][j - 1]) % MOD;
		}
	}
}
int main(int argc, char const *argv[]) {
	freopen("input.txt", "r", stdin);
	int T; scanf("%d", &T);
	init();
	while (T--) {
		long long  n, k;
		scanf("%lld %lld", &n, &k);
		if (k > n) {
			printf("0\n");
		}
		else {
			long long  ans = 1;
			for (int i = 1; i <= k; i++) {
				ans *= i;
				ans %= MOD;
			}
			printf("%lld\n", ans * s[n][k] % MOD);
		}

	}
	return 0;
}