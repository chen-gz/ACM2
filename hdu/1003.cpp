//hdu 1003
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1000010;
struct node {
	int beg;
	int end;
	int val;
} dp[N];
int a[N];
int main()
{
	int n;
	int t;
	cin >> t;
	int qqqqq;
	for (int k = 1; k <= t; k++)
	{
		memset(dp, 0, sizeof(dp));
		memset(a, 0, sizeof(a));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		dp[1].val = a[1];
		dp[1].beg = 1;
		dp[1].end = 1;
		int ans = -1, beg = 1, end = 1;
		for (int i = 2; i <= n; i++) {
			if ((dp[i - 1].val >= 0))
			{
				dp[i].val = dp[i - 1].val + a[i];
				dp[i].beg = dp[i - 1].beg;
				dp[i].end = i;
			}
			else
			{
				dp[i].val = a[i];
				dp[i].beg = i;
				dp[i].end = i;
			}
			if (dp[i].val >= ans)
			{
				ans = dp[i].val;
				beg = dp[i].beg;
				end = dp[i].end;
			}
		}
		cout << "Case " << k << ":" << endl
		     << ans << " " << beg << " " << end << endl;
		if (k != t)
			cout << endl;
	}
}
