#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	//FILE *fr = freopen("/home/pocky/Program/in", "r", stdin),
	//      *fo = freopen("/home/pocky/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	int min1 = 1019999999;
	int max1 = -1;
	int min2 = 1019999999;
	int max2 = -1;
	for (int i = 0; i < n; ++i) {
		int l, r; cin >> l >> r;
		min1 = min(min1, r);
		max2 = max(max2, l);
	}
	int m; cin >> m;
	for (int i = 0; i < m; ++i) {
		int l, r; cin >> l >> r;
		max1 = max(max1, l);
		min2 = min(min2, r);
	}
	if (max1 > min1 || max2 > min2) {
		if (max1 - min1 > max2 - min2)
			cout << max1 - min1;
		else
			cout << max2 - min2;
		cout << endl;
	}
	else
		cout << "0" << endl;
	//fclose(fr); fclose(fo);
}