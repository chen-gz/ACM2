#include <bits/stdc++.h>
using namespace std;
long long  a[100005];
long long addbegin[100005];
long long addend[100005];
set<long long> sum;
set<long long>fuck;
int main(int argc, char const *argv[]) {
	// FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	//       *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	addbegin[0] = a[0];
	addend[0] = a[n - 1];
	for (int i = 1; i < n; ++i) {
		addbegin[i] = addbegin[i - 1] + a[i];
		sum.insert(addbegin[i]);
		addend[i] = addend[i - 1] + a[n - 1 - i];
		fuck.insert(addend[i]);
	}
	if (addbegin[n - 1] % 2 != 0) {
		cout << "NO" << endl;
		return 0;
	}
	if (sum.count(addbegin[n - 1] / 2) || fuck.count(addbegin[n - 1] / 2)) {
		cout << "YES" << endl;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (sum.count(addbegin[n - 1] / 2 + a[i]) || fuck.count(addbegin[n - 1] / 2 + a[n - 1 - i])) {
			// cout << i << endl;
			// cout << a[i] << endl;
			cout << "YES" << endl;
			return 0;
		}
		else {
			sum.erase(addbegin[i]);
			fuck.erase(addend[i]);
		}
	}
	cout << "NO" << endl;
	// cout << "Orz" << endl;
	return 0;
}