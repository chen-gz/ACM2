//
// Created by lucas on 12/30/19.
//
#include <bits/stdc++.h>
using namespace std;
int a[3];
int main() {
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 3; i++) {
			cin >> a[i];
		}
		sort(a, a + 3);
		if (a[2] - a[1] - 1 <= a[0])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
