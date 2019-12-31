#include <bits/stdc++.h>

using namespace std;
int a[int(1e5) + 4];

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, s;
        cin >> n >> s;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int maxValue = -1;
        long long sum = 0;
        int ans = 0;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum > s)
                if (!flag) {
                    sum -= maxValue;
                    flag = true;
                } else break;

            if (maxValue < a[i]) {
                maxValue = a[i];
                ans = i + 1;
            }
        }
        if (accumulate(a, a + n, (long long)0) <= s)
            cout << 0 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
