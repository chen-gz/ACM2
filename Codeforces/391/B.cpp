#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
#define maxn 555555
int mark[maxn];
vector<int> prime(maxn);
int res;
void get_prime(int n) {
	memset(mark, 0, sizeof(mark));
	res = 0;
	for (int i = 2; i <= n; i++) {
		if (!mark[i])
			mark[i] = prime[res++] = i;
		for (int j = 0; j < res && prime[j] * i <= n; j++) {
			mark[i*prime[j]] = prime[j];
			if (i%prime[j] == 0)
				break;
		}
	}
}
int main(int argc, char const *argv[]) {
	//freopen("input.txt", "r", stdin);
	get_prime(500001);
	int n; cin>>n;
	int s,ans  = 1;
	sort(prime.begin(),prime.end());
	for(int i=0; i<n; i++) {
		cin>>s;
		for(int j=2; j<=sqrt(s)+3; j++) {
			if(prime[lower_bound(prime.begin(),prime.end(), s) - prime.begin()]==s) {
				mp[s]++;
				break;
			}
			if(s%j==0) {
				mp[j]++; s/=j;
				while(s%j==0)
					s/=j;
			}
		}
	}
	for(auto i=mp.begin(); i!=mp.end(); i++) {
		ans = max(ans,(*i).second);
	}
	cout<<ans<<endl;
	return 0;
}
