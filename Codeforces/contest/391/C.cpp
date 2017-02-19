#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PB push_back
#define ALL(X) X.begin(), X.end()
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

const int N = 1e6;
const LL MOD = 1e9 + 7;
LL fact[N+1];
int main()
{
	fast_io;
	fact[0] = fact[1] = 1;
	for(LL i=2; i<=N; i++)
		fact[i] = (fact[i-1]*i)%MOD;
	int n,m;
	cin >> n >> m;
	vector< vector<int> > x(m);
	for(int i=0; i<n; i++) {
		int s;
		cin >> s;
		for(int j=0; j<s; j++) {
			int t;
			cin >> t;
			x[t-1].PB(i);
		}
	}
	for(int i=0; i<m; i++)
		sort(ALL(x[i]));
	sort(ALL(x));
	LL ans = 1;
	LL sm = 1;
	for(int i=1; i<m; i++) {
		if(x[i]==x[i-1])
			sm++;
		else
			ans = (ans*fact[sm])%MOD, sm = 1;
	}
	ans = (ans*fact[sm])%MOD;
	cout << ans << endl;
	return 0;
}
