#include <bits/stdc++.h>
using namespace std;
void DFS(int x, int y);
char ch[60][60];
int m, n, k;
struct Block {
	std::vector<pair<int, int>> mem;
	int cnt;
	Block() { cnt = 0; };
};
int pos;
Block block[5000];
bool vis[55][55];
bool cmp(Block a, Block b) {
	return a.cnt < b.cnt;
}
int main(int argc, char const *argv[]) {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= m + 1; i++) {
		ch[0][i] = '.';
		ch[n + 1][i] = '.';
	}
	for (int i = 1; i <= n; i++) {
		ch[i][0] = '.';
		char temp[55];
		scanf("%s", temp);
		for (int j = 0; j < m; j++) {
			ch[i][j + 1] = temp[j];
		}
		ch[i][m + 1] = '.';
	}
	DFS(0, 0); pos++;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (ch[i][j] == '.' && vis[i][j] == false) {
				DFS(i, j);
				pos++;
			}
		}
	}
	int ans = 0;
	sort(block + 1, block + pos, cmp);
	for (int i = 1; i < pos - k; i++) {
		for (int j = 0; j < block[i].mem.size(); j++) {
			ch[block[i].mem[j].first][block[i].mem[j].second] = '*';
			ans++;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%c", ch[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}

void DFS(int x, int y) {
	vis[x][y] = true;
	block[pos].mem.push_back(pair<int, int>(x, y));
	block[pos].cnt++;
	int dx[] = { 1, -1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] <= n + 1 && x + dx[i] >= 0 && y + dy[i] <= m + 1 && y + dy[i] >= 0) {
			if (ch[x + dx[i]][y + dy[i]] == '.' && vis[x + dx[i]][y + dy[i]] == false) {
				DFS(x + dx[i], y + dy[i]);
			}
		}

	}
}