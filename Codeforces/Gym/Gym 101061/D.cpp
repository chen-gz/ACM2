#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	//FILE *fl = freopen("input.txt", "r", stdin);
	int T; cin >> T;
	int a[5];
	while (T--) {
		for (int i = 0; i < 5; i++) {
			cin >> a[i];
		}
		sort(a, a + 5);
		cout << a[3]*a[4] << "\n";
	}
	//fclose(fl);
	return 0;
}