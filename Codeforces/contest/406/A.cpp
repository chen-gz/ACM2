#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	// FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	//       *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	bool have = false;
	for (int i = 0; i < 1000000; ++i) {
		if (b - d + a * i >= 0 && (b - d + a * i) % c == 0) {
			have = true;
			cout << b + a*i << endl;
			break;
		}
	}
	if (!have ) {
		cout << -1 << endl;
	}
	return 0;
}