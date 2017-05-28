#include <bits/stdc++.h>
std::vector<int> v[100030];
int sum[100030];
using namespace std;
int main(int argc, char const *argv[]) {
	//FILE *fr = freopen("/home/pocky/Program/in", "r", stdin),
	//      *fo = freopen("/home/pocky/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int T; cin >> T;

	while (T--) {
		for (int i = 0; i <= 100030; i++) {
			v[i].clear();
		}
		memset(sum, 0, sizeof(sum));
		int n, m; cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int Q; cin >> Q;
		for (int i = 0; i < Q; ++i) {
			int cmd; cin >> cmd;
			if (!cmd) {
				int u, v; cin >> u >> v;
				sum[u] += v;
			}
			else {
				int u; cin >> u;
				int ans = 0;
				for (int j = 0; j < v[u].size(); ++j) {
					ans += sum[v[u][j]];
				}
				//ans += sum[u];
				cout << ans << endl;
			}
		}
	}
	//fclose(fr); fclose(fo);
}