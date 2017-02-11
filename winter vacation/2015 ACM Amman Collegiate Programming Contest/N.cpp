#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
const int MX = 2e5 + 5;

int Head[MX], Next[MX], rear;
int Low[MX], DFN[MX], dfs_clock;
int Begin, Bridge;
int P[MX];

struct Edge {
	int u, v, sign;
} E[MX];

int find(int x) {
	return P[x] == x ? x : (P[x] = find(P[x]));
}

void Union(int u, int v) {
	int x = find(u), y = find(v);
	P[x]=y;
}

void find_init(int n){
	for(int i = 1; i <= n; i++) P[i] = i;
}

void edge_init() {
	rear = 0;
	memset(Head, -1, sizeof(Head));
	memset(Next, -1, sizeof(Next));
}

void edge_add(int u, int v) {
	E[rear].u = u;
	E[rear].v = v;
	E[rear].sign = false;
	Next[rear] = Head[u];
	Head[u] = rear++;
}

void tarjan_init() {
	Bridge = 0;
	dfs_clock = 0;
	memset(DFN, 0, sizeof(DFN));
}

int tarjan(int u, int from) {
	Low[u] = DFN[u] = ++dfs_clock;

	for(int id = Head[u]; ~id; id = Next[id]) {
		int v = E[id].v;

		if(!DFN[v]) {
			int lowv = tarjan(v, u);
			Low[u] = min(Low[u], lowv);

			if(lowv > DFN[u]) {
				E[id].sign = 1;
				E[id ^ 1].sign = 1;
				Bridge++;
			} else {
				Union(u, v);
			}
		} else if(v != from) {
			Low[u] = min(Low[u], DFN[v]);
		}
	}
	return Low[u];
}

int solve(int u, int from, int &ans) {
	int Max1 = 0, Max2 = 0;
	for(int id = Head[u]; ~id; id = Next[id]) {
		int v = E[id].v;
		if(v == from) continue;

		int t = solve(v, u, ans) + 1;

		if(t > Max1) {
			Max2 = Max1;
			Max1 = t;
		} else if(t > Max2) Max2 = t;
	}

	ans = max(ans, Max1 + Max2);
	return Max1;
}

int main() {
	int T, n, m;
	scanf("%d", &T);

	while(T--) {
		edge_init();
		tarjan_init();

		scanf("%d%d", &n, &m);
		find_init(n);

		for(int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			edge_add(u, v);
			edge_add(v, u);
		}

		tarjan(1, -1);

		int tot = rear;

		edge_init();
		for(int i = 0; i < tot; i++) {
			if(E[i].sign) {
				int u = find(E[i].u), v = find(E[i].v);
				edge_add(u, v);
				Begin = u;
			}
		}

		int ans = 0;
		if(Bridge) solve(Begin, -1, ans);
		printf("%d\n", Bridge - ans);
	}
	return 0;
}
