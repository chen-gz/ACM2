#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
//	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		int n; scanf("%d", &n);
		string str;
		cin >> str;
		int R[1001];
		int P[1001];
		int S[1001];
		R[0] = 0; P[0] = 0; S[0] = 0;
		for (int i = 0; i<n; i++) {
			switch (str[i]) {
			case 'R': R[i + 1] = R[i] + 1;
				//R[i+1] = R[i];
				S[i + 1] = S[i];
				P[i + 1] = P[i];
				break;
			case 'P': P[i + 1] = P[i] + 1;
				R[i + 1] = R[i];
				S[i + 1] = S[i];
				//P[i+1] = P[i];
				break;
			case 'S': S[i + 1] = S[i] + 1;
				R[i + 1] = R[i];
				//S[i+1] = S[i];
				P[i + 1] = P[i];
				break;
			}
		}
		int ans = 0;
		int cnt_win = 0;
		int cnt_loss = 0;
		for (int x = 0; x<=n; x++) {
			for (int y = 0; y <= n - x; y++) {
				cnt_win = S[x] + R[x + y] - R[x] + P[n] - P[x + y];
				cnt_loss = P[x] + S[x + y] - S[x] + R[n] - R[x + y];
				if (cnt_win > cnt_loss) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
