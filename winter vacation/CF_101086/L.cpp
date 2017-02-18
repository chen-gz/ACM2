#include <bits/stdc++.h>
using namespace std;
int dp[100005];
set<int> s;
bool judge(int num) {
	int ans = 0;
	while (num > 0) {
		if (num & 1 ) {
			ans ++;
		}
		num /= 2;
	}
	return s.count(ans);
}
int main(int argc, char const *argv[]) {
	freopen("input.txt", "r", stdin);
	s.insert(2); s.insert(3); s.insert(5); s.insert(7); s.insert(11); s.insert(13);
	s.insert(17); s.insert(19); s.insert(23);
	dp[0] = 0;
	for (int i = 1; i < 100005; i++) {
		dp[i] = dp[i - 1] + judge(i);
	}
	int T; scanf("%d", &T);
	while (T--) {
		int L, R; scanf("%d %d", &L, &R);
		if (L == 0) L++;
		if (R == 0) R++;
		printf("%d\n", dp[R] - dp[L - 1]);
	}
	return 0;
}