#include <bits/stdc++.h>
using namespace std;
double planets[65][65];
map<std::string, int> mp;
int pos[61][4];
int main(int argc, char const *argv[]) {
	//freopen("input.txt", "r", stdin);
	int T; scanf("%d", &T);
	auto distance = [](int x, int y) {
						double x1 = pos[x][1] - pos[y][1];
						double x2 = pos[x][2] - pos[y][2];
						double x3 = pos[x][0] - pos[y][0];
						return sqrt(x1*x1 + x2*x2 + x3*x3);
					};

	for (int times = 1; times <= T; times++) {
		mp.clear();
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			std::string tmp;
			cin >> tmp;
			mp[tmp] = i;
			scanf("%d%d%d", &pos[i][0], &pos[i][1], &pos[i][2]);
			for (int j = 0; j <= i; j++) {
				planets[j][i] = planets[i][j] = distance(i, j);
			}
		}
		int m; scanf("%d\n", &m);
		for (int i = 0; i < m; i++) {
			string tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			planets[mp[tmp1]][mp[tmp2]] = 0;
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (planets[i][j] >= planets[i][k] + planets[k][j]) {
						planets[i][j] = planets[i][k] + planets[k][j];
					}
				}
			}
		}
		printf("Case %d:\n", times);
		int q; scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			string tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			printf("The distance from %s to %s is %0.f parsecs.\n", tmp1.c_str(), tmp2.c_str(), planets[mp[tmp1]][mp[tmp2]]);
		}
	}
	return 0;
}
