#include <bits/stdc++.h>
using namespace std;
int fuck[105];
int main(int argc, char const *argv[]) {
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 104; i++) {
		fuck[i] = i % 3 == 0 ? i / 3 : i / 3 + 1;
	}
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		int ans = 0;
		char tmp[105];
		scanf("%s", tmp);
		int cnt = 0;
		int beg = 0;
		while (tmp[beg] != '*' && beg < n)
			beg++;
		if (beg != n && beg !=0)
			ans += fuck[beg - 1];
		else if(beg !=0)
			ans += fuck[beg];
		for (int i = beg + 1; i < n; i++) {
			if (tmp[i] == '.')
				cnt++;
			else {
				cnt -= 2;
				if (cnt == 0)
					continue;
				if(cnt>0)
					ans += fuck[cnt];
				cnt = 0;
			}
		}
		if(cnt>1)
			ans += fuck[cnt - 1];
		cout << ans << endl;
	}

	return 0;
}
