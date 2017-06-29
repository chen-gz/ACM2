#include <bits/stdc++.h>
using namespace std;
long long  a[200005];
long long  sum[200005];
int main(int argc, char const *argv[]) {
	FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	      *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int div = n - k + 1;
	double plus = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i - 1];
	}
	// cout << sum[0] << " " << sum[1];
	for (int i = k; i <= n; i++) {
		plus += sum[i] - sum[i - k];
	}
	// cout << plus << endl;
	double hhh = (double)plus / (double)div;
	cout << setprecision(15) << showpoint << hhh << endl;
	return 0;
}