////在不过我就不玩了
////没有WA点的题WA9发了
//
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<queue>
//using namespace std;
//int vis[2][13][13];
//char map[2][13][13];
//int fx[4][2] = { 1,0,0,1,-1,0,0,-1 };
//struct fuck{
//	int x, y, step, pos;
//};
//int m, n, t;
//int pos;
//int sx, sy;
//void bfs(){
//	queue<fuck>q;
//	fuck now, next;
//	now.x = sx;
//	now.y = sy;
//	now.step = 0;
//	now.pos = pos;
//	q.push(now);
//	vis[now.pos][now.x][now.y] = 1;
//	while (!q.empty()){
//		now = q.front();
//		q.pop();
//		if (now.step>t)
//			break;
//		if (map[now.pos][now.x][now.y] == 'P'){
//			cout << "YES" << endl;
//			return;
//		}
//		for (int i = 0; i<4; i++){
//			next.x = now.x + fx[i][0];
//			next.y = now.y + fx[i][1];
//			if (next.x<1 || next.y<1 || next.x>m || next.y>n || map[now.pos][next.x][next.y] == '*' || vis[now.pos][next.x][next.y] == 1)
//				continue;
//			next.pos = now.pos;
//			if (map[next.pos][next.x][next.y] == '#'){
//				map[next.pos][next.x][next.y] = '*';
//				next.pos = now.pos ^ 1; 
//				if (map[next.pos][next.x][next.y] == '#' || map[next.pos][next.x][next.y] == '*')
//					continue;
//			}
//			vis[next.pos][next.x][next.y] = 1;
//			next.step = now.step + 1;
//			q.push(next);
//		}
//	}
//	cout << "NO" << endl;
//	return;
//}
//int main(){
//	int tt;
//	int i, j;
//	scanf("%d", &tt);
//	while (tt--){
//		pos = 0;
//		memset(vis, 0, sizeof(vis));
//		cin >> m >> n >> t;
//		for (i = 1; i <= m; i++)
//			for (j = 1; j <= n; j++){
//				cin >> map[0][i][j];
//				if (map[0][i][j] == 'S'){
//					sx = i;
//					sy = j;
//					pos = 0;
//				}
//			}
//		for (i = 1; i <= m; i++)
//			for (j = 1; j <= n; j++){
//				cin >> map[1][i][j];
//				if (map[1][i][j] == 'S'){
//					sx = i;
//					sy = j;
//					pos = 1;
//				}
//			}
//		bfs();
//	}
//	return 0;
//}