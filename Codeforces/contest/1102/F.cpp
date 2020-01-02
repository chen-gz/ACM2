#include <bits/stdc++.h>

using namespace std;
const int N = 16;
long long  a[N][10010];
long long  mn1[N][N];
long long  mn2[N][N];
long long  dp[N][N][1 << N];
int n, m;

long long  calc(int st, int fi, int mask) {
    if (dp[st][fi][mask] != -1)
        return dp[st][fi][mask];
    if ((((1 << st) + (1 << fi)) & mask) && (mask - (1<<st) - (1<<fi)) == 0){
		dp[st][fi][mask] = mn1[st][fi];
		return dp[st][fi][mask];
	}
	if(st == fi){
	    if (n != 1)

	    dp[st][fi][mask] = 0;

	    else
            dp[st][fi][mask] = 1e10;

        return dp[st][fi][mask];
	}
    dp[st][fi][mask] = 0;
    for (int i = 0; i < n; i++) {
        if (i != st && i != fi && ((1 << i) & mask)) {
            dp[st][fi][mask] =
                max(dp[st][fi][mask],
                    min(calc(st, i, mask - (1 << fi)), mn1[i][fi]));
        }
    }
    return dp[st][fi][mask];
}

int main(int argc, char const *argv[]) {
//    FILE *file = freopen("../input", "r", stdin);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mn1[i][j] = 1e10;
            for (int k = 0; k < m; k++) {
                mn1[i][j] = min(mn1[i][j], abs(a[i][k] - a[j][k]));
            }
            mn2[i][j] = 1e10; // i为最后一行j为第一行
            for (int k = 0; k < m - 1; k++) {
                mn2[i][j] = min(mn2[i][j], abs(a[i][k] - a[j][k + 1]));
            }
        }
    }
    long long  ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, min(mn2[j][i], calc(i, j, (1 << (n)) - 1)));
        }
    }
    cout << ans << endl;
    return 0;
}
