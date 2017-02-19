#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	//FILE *fl = freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		long long n ; cin >> n;
		long long cnt = 0;
		if (n % 2 != 0) {
			cout << "First Box\n";
			continue;
		}
		while (n % 2 == 0) {
			n /= 2;
			cnt++;
		}
		if (cnt % 2 == 0) {
			cout << "First Box\n";
		}
		else
			cout << "Second Box\n";
	}
	//fclose(fl);
	return 0;
}