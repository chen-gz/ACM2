//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<algorithm>
//#include<set>
//#include<cstdio>
//#include<queue>
//using namespace std;
//#define readn(x) scanf("%d", &x)
//#define reads(x) scanf("%s",x)
//#define P pair<int,int>
//const int inf = 0xfffffff;
//const int maxn = 200002;
//int dp[maxn];
//int last[maxn];
//
//int main() {
//	int n; readn(n);
//	int tmp;
//	memset(last, -1, sizeof(dp));
//	for (int i = 1; i <= n; i++) {
//		readn(tmp);
//		if (last[tmp] == -1) {
//			dp[i] = dp[i - 1]+1;
//		}
//		else {
//			dp[i - 1] < dp[last[tmp]] ? dp[i] = dp[i - 1] + 1 : dp[i] = dp[last[tmp]] + 1;
//		}
//		last[tmp] = i;
//	}
//	cout << dp[n]-1 << endl;
//	return 0;
//}