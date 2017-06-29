#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
bool done[N][N];
bool fa[N][N];
int main(int argc, char const *argv[]) {
	FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	      *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for (int i = 0 ; i < n; i i++) {
		cin >> a[i];
	}
	queue < pair<int, int> > qu;
	dx[] = {0, 0,  1, -1, 0,  0};
	dy[] = {1, -1, 0,  0, 1, -1};
	qu.push(make_pair(0, 0));
	pair<int , int > F;
	while (!qu.empty()) {
		pair<int, int> ac = qu.front();
		qu.pop();
		bool find = false;
		for (int i = 0 ; i < 4; i++) {
			if (done[ac.first + dx[i]][ac.second + dy[i]] == false
			        && a[ac.first + dx[i]][ac.second + dy[i]] != '*'
			        && a[ac.first + dx[i + 1]][ac.second + dy[i + 2]] != '*') {
				done[ac.first + dx[i]][ac.second + dy[i]] = true;
				fa[ac.first + dx[i]][ac.second + dy[i]] = i;
				qu.push(make_pair(ac.first + dx[i], ac.second + dy[i]));
				if (a[ac.first + dx[i]][ac.second + dy[i]] == 'F') {
					F.first = ac.first + dx[i];
					F.second = ac.second + dy[i];
					find = true;
				}
			}
		}
		if (find) {

		}
	}

	return 0;
}