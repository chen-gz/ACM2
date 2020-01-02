#include <iostream>

using namespace std;
#define N 200010
long long a[N];
long long b[N];

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++, a[i] = 0);

    for (int i = 0; i < n / 2; i++)
        cin >> b[i];

    a[0] = 0;
    a[n - 1] = b[0];

    for (int i = 1; i < n / 2; i++) {
        if (b[i] > a[n - i] + a[i - 1]) {
            a[i] = b[i] - a[n - i];
            a[n - i - 1] = a[n - i];
        } else {
            a[i] = a[i - 1];
            a[n - i - 1] = b[i] - a[i - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

    cout << endl;
    return 0;
}
