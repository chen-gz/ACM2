#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int ans1, ans2;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    ans1 = a[n - 1] - a[0];
    ans2 = a[0] + a[1];
    if (ans1 + 1 < ans2)
    {
        cout << "YES" << endl;
        cout << ans1 + 1 << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}