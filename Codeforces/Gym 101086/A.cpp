#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, mon, maxx = 0, minn = 0;
		char c;
		scanf("%d", &n);
		int flag = 1;
		for (int i = 1; i <= n; i++) {
			scanf("%d %c", &mon, &c);
			if (c == '-') {
				if (flag) {
					maxx = minn + mon + 25;
					flag = 0;
				}
				else
					maxx = min(minn + mon + 25, maxx);
			}
			if (c == '+')
				minn += mon + 25;
		}
		printf("%d\n", maxx - minn);

	}
	return 0;
}
