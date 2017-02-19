#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	freopen("input.txt", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		int ans = 0; int sg = 0;
		for (int i = 0; i < n; i++) {
			int b, k; scanf("%d%d", &b, &k);
			if (b & 1) sg = k & 1;
			else if (k % (b + 1) == b) sg = 2;
			else sg = (k % (b + 1)) & 1;
			ans ^= sg;
		}
		if (ans) printf("1\n");
		else printf("2\n");
	}
	return 0;
}