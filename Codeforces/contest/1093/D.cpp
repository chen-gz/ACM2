#include <iostream>
#include <vector>
using namespace std;
#define N int (3e5 + 10)
#define MOD 998244353
long long  cnt1[N], cnt2[N];
long long  pre_mul[N];
long long  status[N];
std::vector<long long > v[N];
void dfs ( long long  now );
bool bad = false;
int main ( int argc, char const *argv[] ) {
	long long  t; cin >> t;
	pre_mul[0] = 1;

	for ( long long  i = 1; i < N; i++ )
		pre_mul[i] = ( pre_mul[i - 1] << 1 ) % MOD;

//	for(int i=0;i<10;i++)
//		cout<<pre_mul[i]<<" ";
//	cout<<endl;
	while ( t-- ) {
		long long  n, m; cin >> n >> m;
		bad = false;

		for ( long long  i = 0 ; i <= n; i++ ) {
			cnt1[i] = 0;
			cnt2[i] = 0;
			status[i] = 0;
			v[i].clear();
		}

		for ( long long  i = 0 ; i < m ; i++ ) {
			long long  tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			tmp1--,tmp2--;

			v[tmp1].push_back ( tmp2 );
			v[tmp2].push_back ( tmp1 );
		}

		long long  index = 1;

		for ( long long  i = 0; i < n; i++ ) {
			if ( status[i] == 0 ) {
				status[i] = index;
				dfs ( i );
				index ++;
			}
			//else
			//	continue;
		}

		for ( long long  i = 0; i < n; i++ ) {
			if ( status[i] > 0 ) {
				cnt1[status[i]]++;

			} else
				cnt2[-status[i]]++;
		}

		long long  ans = 1;

		for ( long long  i = 1; i < index; i++ ) {
			ans *= ( pre_mul[cnt1[i]] + pre_mul[cnt2[i]] ) % MOD;
			ans %= MOD;
		}

		if ( !bad ) cout << ans << endl;
		else cout << 0 << endl;
	}

	return 0;
}

void dfs ( long long  now ) {
	for ( auto i : v[now] ) {
		if ( status[i] == 0 ) {
			status[i] = -status[now];
			dfs ( i );

		} else if ( status[i] != -status[now] )
			bad = true;
	}
}
