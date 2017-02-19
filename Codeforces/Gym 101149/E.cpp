#include <bits/stdc++.h>
using namespace std;
long long a[200005][2];
int main(int argc, char const *argv[]) {
	freopen("input.txt", "r", stdin);
	long long n; cin >> n;
	long long max = -1000000000002;
	for (long long i = 0; i < n; i++) {
		scanf("%lld %lld", &a[i][0], &a[i][1]);
		if (max < a[i][0])
			max = a[i][0];
	}
	long long ans = 0;
	for (long long i = 0; i < n; i++) {
		if (a[i][1] >= max) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}