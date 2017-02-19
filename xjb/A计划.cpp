///*
//'.' ¿ÕµØ£¬
//¡®#¡¯ ´«ËÍ
//¡®*¡®Ç½
//*/
////FUCK
//WA
//#include<iostream>
//#include<cstdio>
//#include<string>
//#include<cstring>
//#include<queue>
//using namespace std; 
//string map1[15];
//string map2[15];
//struct node {
//	int x; int y; int step; int w;
//	node(int x, int y, int step, int w) {
//		this->x = x;
//		this->y = y;
//		this->step = step;
//		this->w = w;
//	}
//};
//int dx[4] = { 0,1,-1,0 };
//int dy[4] = { -1,0,0,1 };
//bool vmap1[15][15];
//bool vmap2[15][15];
//int BFS(int n, int m,int stx,int sty,int enx,int eny) {
//	memset(vmap1, false, sizeof(vmap1));
//	memset(vmap2, false, sizeof(vmap2));
//	queue<node> q;
//	while (!q.empty())
//		q.pop();
//	q.push(node(stx, sty, 0, 0));
//	vmap1[stx][sty] = true;
//	while (!q.empty()) {
//		node tmp = q.front(); q.pop();
//		for (int i = 0; i < 4; i++) {
//			int x = tmp.x + dx[i];
//			int y = tmp.y + dy[i];
//			if (x >= 0 && x < n && y >= 0 && y < m) {
//				if (tmp.w == 0) {
//					if (vmap1[x][y] == false) {
//						vmap1[x][y] = true;
//						if (map1[x][y] == '.') {
//							q.push(node(x, y, tmp.step + 1, 0));
//						}
//						else if (map1[x][y] == '#' && (map2[x][y]=='.' || map2[x][y]=='P') && vmap2[x][y] == false) {
//							if(map2[x][y] == 'P') {
//								return tmp.step + 1;
//							}
//							vmap2[x][y] = true;
//							q.push(node(x, y, tmp.step + 1, 1));
//						}
//					}
//				}
//				else if (tmp.w == 1) {
//					if (vmap2[x][y] == false) {
//						vmap2[x][y] = true;
//						if (map2[x][y] == '.') {
//							q.push(node(x, y, tmp.step + 1, 1));
//						}
//						else if (map2[x][y] == '#'&& map1[x][y] == '.'&& vmap1[x][y]==false) {
//							vmap1[x][y] = true;
//							q.push(node(x, y, tmp.step + 1, 0));
//						}
//						else if (map2[x][y] == 'P') {
//							return tmp.step + 1;
//						}
//					}
//				}
//			}
//		}
//	}
//	return -1;
//}
//int main() {
//	int n, m;
//	int C; cin >> C;
//	while (C--) {
//		cin >> n >> m;
//		int t; cin >> t;
//		for (int i = 0; i < n; i++)
//			cin >> map1[i];
//		for (int i = 0; i < n; i++)
//			cin >> map2[i];
//		int stx, sty, enx, eny;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				if (map1[i][j] == 'S') {
//					stx = i; sty = j;
//				}
//				if(map2[i][j] == 'P') {
//					enx = i; eny = j;
//				}
//			}
//		}
//		int mstep = BFS(n, m,stx,sty,enx,eny);
//		if (t>=mstep && mstep!=-1)
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//}