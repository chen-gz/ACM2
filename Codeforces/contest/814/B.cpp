#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
int a[N], b[N];
int ans[N];
set<int> hhh;
int main(int argc, char const *argv[]) {
	// FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	//       *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int ac = 0 ;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		hhh.insert(a[i]);
	}
	for (int i = 0; i < n; ++i) {
		ans[i] = a[i];
	}
	int tmp[N];
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		if (b[i] != a[i]) {
			tmp[ac++] = i;
		}
	}
	// cout << ac << endl;
	assert(ac < 3);
	if (ac == 2)	{
		ans[tmp[0]] = b[tmp[0]];
		bool OK = true;
		sort(ans, ans + n);
		for (int i = 1; i < n; ++i) {
			if (ans[i] == ans[i - 1]) {
				OK = false;
				break;
			}
		}
		if (OK)
			a[tmp[0]] = b[tmp[0]];
		else
			a[tmp[1]] = b[tmp[1]];
	}
	if (ac == 1) {
		for (int i = 1; i <= n; ++i) {
			if (hhh.count(i) == 0) {
				a[tmp[0]] = i;
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}