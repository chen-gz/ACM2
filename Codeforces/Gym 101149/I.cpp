#include <bits/stdc++.h>
using namespace std;
std::vector<int> v[2000005];
bool ans[2000005];
int main(int argc, char const *argv[]) {
//	freopen("input.txt","r",stdin);
	int n, m; cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		v[--a].push_back(--b);
		v[b].push_back(a);
	}
	int pos = 1, minsize = 100000000;
	for (int i = 0; i < n; i++) {
		if (v[i].size() < minsize) {
			minsize = v[i].size();
			pos = i;
		}
	}
	ans[pos] = 1;
	for (int i = 0; i < v[pos].size(); i++) {
		ans[v[pos][i]] = 1;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", !ans[i] );
	}
	return 0;
}
