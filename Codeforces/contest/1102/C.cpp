#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
//    FILE *file = freopen("../input", "r", stdin);
    int n, x, y;
    cin >> n >> x >> y;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp <= x) cnt++;
    }
    if (x > y)
        cout << n;
    else
        cout << cnt / 2 + cnt % 2;
    cout << endl;
    return 0;
}
