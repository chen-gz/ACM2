#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[105];
int main(int argc, char const *argv[]) {
	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		int tmp = 100 - a[n-1];
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i]+tmp >= 50)
				break;
			cnt++;
		}
		cout << n -cnt << endl;
	}

	return 0;
}
