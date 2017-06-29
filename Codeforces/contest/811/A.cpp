#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	      *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < 1000000000; i++) {
		if (i % 2 == 1) {
			a -= i ;
			if (a < 0 ) {
				cout << "Vladik" << endl;
				break;
			}
		}
		else {
			b -= i;
			if (b < 0) {
				cout << "Valera" << endl;
				break;
			}

		}
		cout << a << " " << b << endl;

	}
	return 0;
}
