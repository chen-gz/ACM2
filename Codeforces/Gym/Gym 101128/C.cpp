//合并果子
#include <bits/stdc++.h>
using namespace std;
int main () {
	//freopen("input.txt","r",stdin);
	priority_queue<long long, vector<long long>, greater<long long> > q;
	long long T; cin >> T;
	while (T--) {
		long long ans = 0;
		long long n; cin >> n;
		for (long long i = 0; i < n; i++) {
			long long tmp; cin >> tmp;
			q.push(tmp);
		}
		while (q.size() != 1) {
			long long a = q.top(); q.pop();
			long long b = q.top(); q.pop();
			ans += a + b;
			q.push(a + b);
		}
		cout << ans << endl;
		while (!q.empty()) q.pop();

	}
}
