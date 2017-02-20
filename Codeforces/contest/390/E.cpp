#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <iostream>
#include <bitset>
using namespace std;
const int N = 405;
const int ALPHA = 26;
bitset<N> b[ALPHA][N];
bitset<N> result[N];
bitset<N> getShifted(const bitset<N>& b, int len, int shift) {
	assert(0 <= shift && shift < len);
	return (b >> shift) | (b << (len - shift));
}
int main() {
	//freopen("input.txt", "r", stdin);
	int n, m; cin >> n >> m;
	string str;
	for (int i = 0; i<n; i++) {
		cin >> str;
		for (int j = 0; j<m; j++) {
			b[(int)(str[j] - 'a')][i][j] = true;
		}
	}

	int r, c; cin >> r >> c;
	string patt[N];
	for (int i = 0; i<r; i++) {
		cin >> patt[i];
	}

	for (int i = 0; i<n; i++) {
		result[i] = ~result[i];
	}

	for (int x = 0; x<r; x++) {
		for (int y = 0; y<c; y++) {
			if (patt[x][y] == '?')
				continue;
			int c = patt[x][y] - 'a';
			int shiftx = ((-x) % n+n)%n;
			int shifty = (y % m + m) % m;
			for (int i = 0; i<n; i++) {
				int nx = i + shiftx;
				if (nx >= n)
					nx -= n;
				result[nx] &= getShifted(b[c][i], m, shifty);
			}
		}
	}
	for (int i = 0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout << result[i][j];
		}
		cout<<endl;
	}
	cout << endl;
	return 0;
}