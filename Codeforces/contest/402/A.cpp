#include <bits/stdc++.h>
const int  N = 100005;
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int a[N], b[N], gg[N], ac[N];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(gg, 0, sizeof(gg));
	memset(ac, 0, sizeof(ac));

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		gg[a[i]] ++;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		ac[b[i]] ++;
	}
	int accept = 0;
	for (int i = 1; i <= 5; i++) {
		accept += abs(gg[i] - ac[i]) / 2;
		if ((gg[i] + ac[i]) % 2) {
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << accept / 2 << endl;
	return 0;
}
