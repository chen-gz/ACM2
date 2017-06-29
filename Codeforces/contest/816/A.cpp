#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	// FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	//       *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int n, m;
	char ch;
	cin >> n >> ch >> m;
	int cnt = 0 ;
	while (n / 10 != m % 10 || n % 10 != m / 10) {
		cnt++;
		m++;
		if (m == 60) {
			n++;
			m = 0;
		}
		if (n == 24) {
			n = 0;
		}
	}
	cout << cnt << endl;
	return 0;
}