#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Ring {
	int in;
	int ou;
	int h;
};
const int INF = 0xfffffff;
Ring ring[100005];
bool cmp(Ring a, Ring b) {
	return a.ou < b.ou;
}
//pair<int, int> dp[100005];
long long  dp[100005];
int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	FILE *fl = freopen("input.txt", "r", stdin);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ring[i].in >> ring[i].ou >> ring[i].h;
	}
	sort(ring, ring + n, cmp);
	int l = 0, r = 1;
	while (r < n) {
		if (ring[l].ou == ring[r].ou) {
			ring[l].h += ring[r].h;
			ring[l].in = min(ring[l].in, ring[r].in);
			r++;
		}
		else {
			ring[++l] = ring[r];
			r++;
		}
	}
	int cnt = ++l;
	dp[0] = ring[0].h;
	long long ans = dp[0];
	for (int i = 1; i < cnt; i++) {
		long long  maxn = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (ring[j].ou < ring[i].in) {
				break;
			}
			maxn = max(dp[j], maxn);
		}
		dp[i] = ring[i].h + maxn;
		ans = max(dp[i], ans);
	}
	cout << ans << endl;
	fclose(fl);
	return 0;
}