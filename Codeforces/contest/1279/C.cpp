//
// Created by lucas on 12/30/19.
//

#include <bits/stdc++.h>

#define N int(1e5+10)
int a[N], b[N], c[N];
using namespace std;

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        long long ans = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            c[a[i]] = i;
        }
        for (int i = 0; i < m; i++)
            cin >> b[i];
        int maxValue = 0;
        for (int i = 0; i < m; i++) {
            if (maxValue >= c[b[i]]) {
                ans += 1;
            } else {
                ans += 2 * (long long)(c[b[i]] - i) + 1;
                maxValue = c[b[i]];
            }

        }
        cout<<ans<<endl;
    }
}