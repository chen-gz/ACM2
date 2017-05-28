#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	//FILE *fr = freopen("/home/pocky/Program/in", "r", stdin),
	//      *fo = freopen("/home/pocky/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	long long n, m;
	cin >> n >> m;
	if (n > m) {
		long long l = 0, r = 1414213565;
		long long ac = n - m;
		while (r - l > 0) {
			long long mid = (l + r) / 2;
			if ((ac - mid * (mid + 1) / 2) < 0)
				r = mid;
			else
				l = mid + 1;
			if ((ac - mid * (mid + 1) / 2) <= 0)
				r = mid;
		}
		cout << m + r << endl;
	}
	else  if (n == m) {
		cout << m << endl;
	}
	else if (n < m) {
		cout << n << endl;
	}
	cout << endl;
	//fclose(fr); fclose(fo);
}