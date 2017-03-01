#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	FILE *fl = freopen("input.txt", "r", stdin);
	long long  n, k; cin >> n >> k;
	int ac = 0 , gg = 0, ans = 0;
	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}
	while (ac < k && n > 0) {
		if (n % 10 == 0 ) {
			ac ++;
		}
		else {
			ans ++;
		}
		n = n / 10;
		gg++;
	}
	if (ac < k ) {
		cout << gg - 1 << endl;
	}
	else
		cout << ans << endl;

	fclose(fl);
	return 0;
}