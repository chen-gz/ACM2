#include <bits/stdc++.h>
using namespace std;
int main() {
	// FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	//       *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	int k = 0;
	int beg = 0;
	int hhh = n;
	if (n < 10) {
		cout << '1' << endl;
		return 0;
	}
	while (n >= 10) {
		k++;
		n /= 10;
	}
	long long ac = 0;
	beg = n;
	if (beg == '9') {
		// cout << '1';
		ac = ac * 10 + 1;
	}
	else
		ac = ac * 10 + beg + 1;
	for (int i = 0; i < k; ++i)
	{
		ac = ac * 10 + 0;
	}
	if (beg == '9')
		ac = ac * 10 + 0;
	// cout << ac << endl;
	cout << ac - hhh << endl;
	return 0;

}
