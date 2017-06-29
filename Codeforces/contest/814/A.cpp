#include <bits/stdc++.h>
using namespace std;
int a[200];
int main(int argc, char const *argv[])
{
	int n, k;
	cin >> n >> k;
	if (k >= 2) {
		cout << "Yes" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> k;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0 ) {
			a[i] = k;
		}
		if (a[i + 1] == 0 ) {
			a[i + 1] = k;
		}
		if (a[i + 1] < a[i]) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}