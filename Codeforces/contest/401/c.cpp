#include <bits/stdc++.h>
using namespace std;
int a[100001];
int b[100001];
int c[100001];
pair<int, int> P[5000000];
int cnt;
int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	FILE *fl = freopen("input.txt", "r", stdin);
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[j];
			if (b[j] < a[j]) {
				P[cnt].first = c[j];
				P[cnt].second = i;
				c[j] = i;
			}
			a[j] = b[j];
		}
	}
	sort(P, P + cnt, cmp);
	fclose(fl);
	return 0;
}