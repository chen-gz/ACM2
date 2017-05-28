#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const int N = 200030;
std::vector<int> g[N];
int color[N];
bool done[N];
int Dad[N];
int Granpa[N];
int ans = 0;
int main(int argc, char const *argv[]) {
	FILE *fr = freopen("/home/pocky/Program/in", "r", stdin),
	      *fo = freopen("/home/pocky/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int x, y; cin >> x >> y;
		g[--x].push_back(--y);
		g[y].push_back(x);
		ans = max(ans , (int)g[x].size() + 1);
		ans = max(ans , (int)g[y].size() + 1);

	}
	queue<int> q;
	color[0] = 1;
	done[0] = true;
	q.push(0);
	while (!q.empty()) {
		int ac = q.front(); q.pop();
		int co = 1;
		for (int i = 0; i < g[ac].size(); ++i) {
			int temp = g[ac][i];
			if (done[temp])
				continue;
			q.push(temp);
			done[temp] = true;
			Dad[temp] = ac;
			Granpa[temp] = Dad[ac];
			while (co == color[Dad[temp]] || co == color[Granpa[temp]]) {
				co++;
			}
			color[temp] = co++;
		}


	}
	cout << ans << endl;
	for (int i = 0; i < n; ++i) {
		cout << color[i] << " ";
	}
	cout << endl;
	fclose(fr); fclose(fo);
}