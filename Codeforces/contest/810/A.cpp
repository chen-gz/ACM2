#include <bits/stdc++.h>
using namespace std;
double a[105];
int main(int argc, char const *argv[]) {
	// FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	//       *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	double n; double k;
	cin >> n >> k;
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i] ;
	}
	double ans = ( 2 * k * n - n - 2 * sum );
	// cout << ans << endl;
	if (ans <= 0) {
		cout << 0 << endl;
		return 0;
	}
	int out = (int)ans;
	if (out < ans ) out ++;
	cout << out << endl;
	return 0;
}