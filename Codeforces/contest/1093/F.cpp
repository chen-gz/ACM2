#include <iostream>

#define N int(2e5 + 5)
#define MOD 998244353
using namespace std;
int a[N];
long long dp[N][200];
long long sumdp[N];
int cnt[N][105];

int main(int argc, char const *argv[]) {
//    FILE *file = freopen("../input", "r", stdin);
    int n, k, len;
    cin >> n >> k >> len;
    bool ok = true;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++)
            cnt[i][j] = cnt[i - 1][j] + (a[i] == -1 || a[i] == j);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (!(a[i] == -1 || a[i] == j))
                continue;

            long long add = 1;
            if (i > 1) add = sumdp[i - 1];
            dp[i][j] = add;

            dp[i][j] %= MOD;
            bool ok = i+1 >= len;
            int l = max(1, i - len);
            int r = i;
            ok &= (r - l == cnt[r][j] - cnt[l][j]);
            if (!ok) continue;
            if (i == len) {
                dp[i][j]--;
                continue;
            }
            add = sumdp[i - len] - dp[i - len][j];
            add %= MOD;
            dp[i][j] += MOD;
            dp[i][j] -= add;
            dp[i][j] %= MOD;
        }
        for (int j = 1; j <= k; j++) {
            sumdp[i] += dp[i][j];
            sumdp[i] %= MOD;
        }
    }
    cout << sumdp[n] << endl;
    return 0;
}
