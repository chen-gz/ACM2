///*
//*	题意：在n*m的图中‘#’表示草坪‘ . ’表示空地，可以选择在任意的两个草坪格子点火，火每 1 s会向周围四个格子扩散，问选择那两个点使得燃烧完所有的草坪花费时间最小。
//*
//*/
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <vector>
//#include<string>
//#include <queue>
//using namespace std;
//bool vis[15][15];
//string grass[11];
//int to[4][2] = { 0,1,0,-1,1,0,-1,0 };
//struct node {
//	int x, y, t;
//	node(int x, int y, int t) {
//		this->x = x;
//		this->y = y;
//		this->t = t;
//	}
//};
//int bfs(node a, node b, int n, int m) {
//	int s;
//	memset(vis, 0, sizeof vis);
//	queue<node> q;
//	a.t = b.t = 0;
//	vis[a.x][a.y] = vis[b.x][b.y] = 1;
//	q.push(a); q.push(b);
//	while (!q.empty()) {
//		a = q.front();
//		q.pop();
//		s = a.t;
//		for (int i = 0; i < 4; i++) {
//			b.x = a.x + to[i][0];
//			b.y = a.y + to[i][1];
//			if (b.x >= 0 && b.x < n&&b.y >= 0 && b.y < m && !vis[b.x][b.y] && grass[b.x][b.y] == '#') {
//				vis[b.x][b.y] = 1;
//				b.t = a.t + 1;
//				q.push(b);
//			}
//		}
//	}
//	return s;
//}
//vector<node> v;
//int main() {
//	int T; cin >> T;
//	for (int q = 1; q <= T; q++) {
//		int n, m; cin >> n >> m;
//		v.clear();
//		for (int i = 0; i < n; i++)
//			cin >> grass[i];
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				if (grass[i][j] == '#')
//					v.push_back(node(i, j, 0));
//			}
//		}
//		int ans = 0xffff;
//		for (int i = 0; i < v.size(); i++) {
//			for (int j = i; j < v.size(); j++) {
//				bool flag = true;
//				int tmp = bfs(v[i], v[j], n, m);
//				for (int k = 0; k < v.size(); k++)
//					if (!vis[v[k].x][v[k].y])
//					{
//						flag = 0;
//						break;
//					}
//
//				if (flag) ans = min(ans, tmp);
//			}
//		}
//		cout << "Case " << q << ": ";
//		if (ans == 0xffff) cout << -1 << endl;
//		else cout << ans << endl;
//	}
//	return 0;
//}