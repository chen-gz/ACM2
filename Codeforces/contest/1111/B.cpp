
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long  a[N];
int main() {
    //FILE *file = freopen("../input", "r", stdin);
    long long  n, k, m;
    cin >> n >> k >> m;
    long long  sum =0 ;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];

    }
	sort(a +1, a + n +1);
	long double ans = (long double)(sum + min(k*n,m))/(long double)n;
	for(int i=1;i<=min(n-1,m);i++){
		sum -= a[i];
		long double tmp = (long double)(sum + min(k*(n-i),m-i))/(long double)(n-i);
		ans = max(ans, tmp);
	}
	cout<<fixed<<setprecision(20)<<ans<<endl;
	return 0;
}
