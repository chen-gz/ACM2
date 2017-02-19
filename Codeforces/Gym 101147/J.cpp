#include <bits/stdc++.h>
using namespace std;
void DFS(int start);
struct edge {
	int to, len;
	edge(int t, int l) {
		to = t;
		len = l;
	}
};
int volume[500005];
bool vis[500005];
int need_volume[500005];
std::vector<edge> G[500005];
int main(int argc, char const *argv[]) {
	int T; scanf("%d", &T);
	while (T--) {
		memset(need_volume, 0, sizeof(need_volume));
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &volume[i]);
		}
		for (int i = 0; i < n - 1; i++) {
			int f, t, len;
			scanf("%d%d%d", &f, &t, &len);
			G[f].push_back(edge(t, len));
			G[t].push_back(edge(f, len));
		}
		DFS(1);
	}
	return 0;
}

void DFS(int start) {
	vis[start] = true;
	for (int i = 0; i < G[start].size(); i++) {
		int temp = G[start][i].to;
		if (!vis[temp]) {
			vis[temp] = true;
			need_volume[i] = need_volume[start] + G[start][i].len;
		}
	}
}