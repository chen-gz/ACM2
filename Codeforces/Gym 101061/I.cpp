#include <bits/stdc++.h>
using namespace std;
int ac[27];
int gg[27];
int main(int argc, char const *argv[]) {
//	FILE* fl = freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int T; cin >> T;
	while (T--) {
		memset(ac, 0, sizeof(ac));
		memset(gg, 0, sizeof(gg));
		string s1; string s2;
		cin >> s1 >> s2;
		for (int i = 0; i < s1.length(); i++) {
			ac[(int)(s1[i] - 'a')]++;
		}
		for (int i = 0; i < s2.length(); i++) {
			gg[(int)(s2[i] - 'a')]++;
		}
		int ans = 0;
		for (int i = 0; i < 26; i++) {
			ans += abs(ac[i] - gg[i]);
		}
		cout << ans << '\n';
	}
//	fclose(fl);
	return 0;
}