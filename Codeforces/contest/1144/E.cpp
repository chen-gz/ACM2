#include <bits/stdc++.h>
using namespace std;
int ans[int(2e5 + 10)];
int main() {
    int n;
    cin >> n;
    string s, t, ans;
    cin >> s >> t;
    for (int i = 0; i < n; i++) {
        ans.push_back(t[i] + s[i] - 'a' - 'a');
    }
    for (int i = n - 1; i > 0; i--) {
        ans[i - 1] += (ans[i] / 26);
        ans[i] %= 26;
    }
    if (n > 1) {
        ans[1] += (ans[0] % 2) * 26;
        ans[0] /= 2;
    }
    for (int i = 1; i < n - 1; i++) {
        ans[i + 1] += (ans[i] % 2) * 26;
        ans[i] /= 2;
    }
    ans[n - 1] /= 2;
    for (int i = 0; i < n; i++) {
        ans[i] += 'a';
    }
    cout << ans << endl;
    return 0;
}
