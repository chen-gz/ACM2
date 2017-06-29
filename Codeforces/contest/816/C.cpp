#include <bits/stdc++.h>
using namespace std;
const int N  = 200;
const int M = 200;
int a[N][M];
int main(int argc, char const *argv[]) {
	// FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	//       *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int n, m;
	bool fuck = false;
	cin >> n >> m;
	int minR[N];
	for (int i = 0; i < 106; i++) {
		minR[i] = 50000;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	if (n > m) {
		fuck = true;
		for (int i = 0 ; i < n; i++) {
			for (int j = i; j < n; j++) {
				swap(a[i][j], a[j][i]);
			}
		}
		swap(n, m);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (minR[i] >= a[i][j] )
				minR[i] = a[i][j];
		}
	}
	int cnt = 0 ;
	for (int i = 0 ; i < n; i++) {
		if (minR[i] == 0 )
			continue;
		else {
			cnt += minR[i];
		}
		for (int j = 0; j < m; ++j) {
			a[i][j] -= minR[i];
		}
	}


	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; ++j) {
	// 		cout << a[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	//column
	bool err = false;
	for (int i = 0; i < m; ++i) {
		if (a[0][i] != 0)
			cnt += a[0][i];
		for (int j = 0; j < n; ++j) { //j row
			if (a[j][i] != a[0][i]) {
				err = true;
			}
		}
	}
	if (err) {
		cout << -1 << endl;
	}
	else {
		cout << cnt << endl;
		for (int j = 0; j < n; ++j) {
			if (minR[j] != 0 ) {
				for (int k = 0; k < minR[j]; ++k) {
					if (fuck) {
						cout << "col " << j + 1 << endl;
					}
					else
						cout << "row " << j + 1 << endl;
				}
			}
		}
		for (int j = 0; j < m; ++j) {
			if (a[0][j] != 0 ) {
				for (int k = 0; k < a[0][j]; ++k) {
					if (fuck) {
						cout << "row " << j + 1 << endl;
					}
					else
						cout << "col " << j + 1 << endl;
				}
			}
		}
	}
}