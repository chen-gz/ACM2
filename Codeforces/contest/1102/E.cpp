#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
#define N 200005
#define MOD 998244353
map<int, int> m;
int data[N];
int main() {
	FILE *file = freopen("../input", "r", stdin);
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        m[data[i]] = i;
    }
    int next = m[data[0]];
    int ans = 1;
    for (int i = 0; i < n; i++) {
        while (i < next) {
            i++;
            next = max(next, m[data[i]]);
        }
        if (next + 1 < n) {
            ans <<= 1;
            ans %= MOD;
        }
        next = max(next, m[data[i + 1]]);
    }
    cout << ans << endl;
    return 0;
}
