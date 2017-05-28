#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	      *fo = freopen("/home/wendell/Program/out", "w", stdout);
	string str;
	cin >> str;
	int ans = 0;
	bool before_v = false;
	bool add = false;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == 'V') {
			if (str[i + 1] == 'K') {
				ans++;
				i++;
				continue;
			}
			if (str[i + 1] == 'V' && str[i + 2] != 'K') {
				if (!add) {
					add = true;
				}
			}
		}
		else {
			if (str[i - 1] == 'K' && str[i - 2] != 'V') {
				add = true;
			}
		}
	}
	cout << ans + add << endl;
	return 0;
}