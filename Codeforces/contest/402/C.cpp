#include <bits/stdc++.h>
using namespace std;
const int  N = 200003;
struct node {
	int first, second, m;
} accept[N];
typedef long long ll;
bool cmp(node a, node b);
int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i ++)
		cin >> accept[i].first;
	for (int i = 0; i < n; i ++)
		cin >> accept[i].second;
	for (int i = 0; i < n; i ++)
		accept[i].m = accept[i].second - accept[i].first;
	ll ans = 0;
	int position = 0;
	sort(accept, accept + n, cmp);
	while (position < k) {
		ans += (ll)accept[position].first;
		position ++;
	}
	while (accept[position].m > 0) {
		ans += (ll)accept[position].first;
		position ++;
	}
	while (position < n) {
		ans += (ll)accept[position].second;
		position ++;
	}
	cout << ans << endl;
	return 0;
}
bool cmp(node a, node b) {
	return a.m > b.m;
}