#include <bits/stdc++.h>
char map[103][103];
int ans[103][103];
int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	int m, n;
	while (scanf("%d %d", &n, &m) && n != 0) {
		memset(ans, 0, sizeof(ans));
		for (int i = 1; i <= n; i++) {
			scanf("%s", map[i] + 1);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == '*') {
					ans[i - 1][j]++;
					ans[i + 1][j]++;
					ans[i][j - 1]++;
					ans[i][j + 1]++;
					ans[i + 1][j + 1]++;
					ans[i - 1][j - 1]++;
					ans[i + 1][j - 1]++;
					ans[i - 1][j + 1]++;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == '*')
					std::cout << "*";
				else
					std::cout << ans[i][j];
			}
			std::cout << '\n';
		}
	}
	return 0;
}
