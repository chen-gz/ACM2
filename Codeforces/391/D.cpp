#include <bit/stdc++.h>
using namespace std;
#define ll long long
ll dp[76][76][2];
const ll mod = 1e9+7;
int main(){
	int n; cin>>n;
	string str; cin>>str;
	for(int i=0; i<n; i++) {
		if(str[i] == '0') {
			for(int j=1; j<i; j++) {
				if(str[i-1] == '0')
					dp[i][j][0] = dp[i-1][j][0];
				else
					dp[i][j][0] = dp[i-1][j-1][1];
				dp[i][j][1] = dp[i-1][j][1];
			}
		}
		else if(str[i] == '1') {
			for(int j=1; j<i; j++) {
				dp[i][j][1] = dp[i-1][j-1][1] + dp[i-1][j+1][0];
			}
		}
	}
	int ans =0;
	for(auto i=0; i<n; i++) {
		ans +=dp[n-1][i][1];
	}
	cout<<ans<<endl;

}
