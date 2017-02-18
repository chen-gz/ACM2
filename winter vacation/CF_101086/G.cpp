#include <bits/stdc++.h>
using namespace std;
char str[3][3500];
int ans = -1;
int main(int argc, char const *argv[]) {
	freopen("input.txt", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < 3; i++) {
			scanf("%s", str[i]);
		}
		int cnt;
		ans = -1;
		for (int i = 0; i < 3 * n; i += 3) {
			cnt = 0;
			for (int j = i; j < i + 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (k == 1 && j == i + 1) {
						continue;
					}
					else if (str[k][j] == '*') {
						cnt ++;
					}
				}
			}
			if (cnt > ans ) {
				swap(ans, cnt);
			}
		}
		printf("%d\n", ans * 4);
	}
	return 0;
}