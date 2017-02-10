#include <bits/stdc++.h>
using namespace std;
int k;
const int hhh = 1020;
int sg[1020];
int getsg(int num[], int n) {
	bool hash[30];
	memset(sg, 0, sizeof(sg));
	sg[0] = 0;
	for (int i = 1; i <= n; i++) {
		memset(hash, false, sizeof(hash));
		for (int j = 0; j <= k; j++) {
			int tmp = i - j;
			if (tmp > 0) {
				tmp -= num[tmp];
				if (tmp >= 0)
					hash[sg[tmp]] = true;
			}

		}
		int j;
		for (j = 0; j <= 30; j++) {
			if (!hash[j]) {
				break;
			}
		}
		sg[i] = j;
	}
	return sg[n];
}
int main() {
	//freopen("input.txt", "r", stdin);
	int T; cin >> T; cin >> k;
	int ans = 0;
	int num[1020];
	num[0] = 0;
	while (T--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &num[i]);
		}
		ans ^= getsg(num, n);
	}
	if (ans != 0) {
		std::cout << "Alice can win." << '\n';
	}
	else
		std::cout << "Bob will win." << '\n';
}
