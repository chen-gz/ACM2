#include <bits/stdc++.h>
//int INT_MIN  = -10000;
int arr[1000001];
int dp[1000001];
int Max[1000001];
using std::max;
int main(int argc, char const *argv[]) {
	freopen("input.txt","r",stdin);
	int m,n;
	while (~scanf("%d%d",&m,&n )) {
		int sum_max = INT_MIN;
		memset(dp,0,sizeof(dp));
		memset(arr,0,sizeof(arr));
		memset(Max,0,sizeof(Max));
		arr[0]=0;
		for(int i=1; i<=n; i++) {
			scanf("%d",arr+i);
		}
		for(int i=1; i<=m; i++) {
			sum_max = INT_MIN;
			for(int j=i; j<=n; j++) {
				dp[j] = max(dp[j-1] + arr[j],Max[j-1]+arr[j]);
				Max[j-1] = sum_max;
				sum_max = max(sum_max,dp[j]);
			}
		}
		std::cout << sum_max << '\n';
	}
	return 0;
}
