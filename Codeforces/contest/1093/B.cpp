#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int a[100];

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        bool flag = false;
        char tmp_char = tmp[0];

        for (long unsigned int i = 0; i < tmp.length(); i++) {
            if (tmp[i] != tmp_char) {
                flag = true;
                break;
            }
        }
        sort(tmp.begin(),tmp.end());
        if (flag)
            cout << tmp << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
