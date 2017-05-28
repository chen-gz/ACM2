#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	// FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	//       *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	long long a, b, k; cin >> k >> a >> b;
	long long ans = a / k + b / k;
	if (a == 0 && b != 0 && b % k != 0)
	{
		cout << "-1" << endl;
		return 0;
	}
	else if (b == 0 && a != 0 && a % k != 0)
	{
		cout << "-1" << endl;
		return 0;
	}
	else	if (ans == 0 ) {
		cout << "-1" << endl;
	}
	else if (a % k != 0 && b < k ) {
		cout << "-1" << endl;
	}
	else if (b % k != 0 && a < k ) {
		cout << "-1" << endl;
	}
	else
		cout << ans << endl;
	return 0;
}