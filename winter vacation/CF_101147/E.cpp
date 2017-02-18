#include<bits/stdc++.h>
using namespace std;
const int MAX_V = 200010 + 1;//最大边的个数
#define INT_MAX 2147483647
struct edge {
	int to, cost;
	edge(int to, int cost) {
		this->to = to;
		this->cost = cost;
	}
};
typedef pair<int, int> P;
//int V;//边的实际个数
// 计数开始为0 所以若点 从1开始计算，则V需要+1；
int d[MAX_V];//最短距离
vector<edge> G[MAX_V]; //的格式；
void init() {
	for (int i = 0; i < MAX_V; i++) {
		G[i].clear();
	}
}
void dijkstra(int start, vector<edge> G[], int V, int d[]) {
	//参数说明
	//start 起点 G[] 图， V 点的数量 d[] 为返回的结果
	bool used[MAX_V];
	priority_queue<P, vector<P>, greater<P> > que;
	memset(used, false, sizeof(used));
	fill(d, d + V, INT_MAX);
	d[start] = 0;
	que.push(P(0, start));
	while (!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first || used[v])
			continue;
		used[v] = true;
		for (unsigned int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	freopen("jumping.in", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) {
		init();
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			if (i - tmp >= 0)
				G[i - tmp].push_back(edge(i, 1));
			if (i + tmp < n)
				G[i + tmp].push_back(edge(i, 1));
		}
		dijkstra(n - 1, G, n, d);
		for (int i = 0; i < n; i++) {
			if (d[i] == INT_MAX)
				printf("-1\n");
			else
				printf("%d\n", d[i]);
		}
	}

	return 0;
}