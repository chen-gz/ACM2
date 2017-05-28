#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	freopen("input.txt", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d %d", &n, &m);
		if (n > m) {
			printf("%d\n", n * n);
		}
		else
			printf("%d\n", m * m);
	}
	return 0;
}