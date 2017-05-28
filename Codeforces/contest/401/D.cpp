#include <bits/stdc++.h>
using namespace std;
string str[500005];
int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	//FILE *fl = freopen("input.txt", "r", stdin);
	char ch;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ch >> str[i];
	}
	for (int i = n - 1; i > 0; i--) {
		if (str[i] < str[i - 1]) {
			for (int j = 0; j < str[i - 1].length() && j < str[i].length(); j++) {
				if (str[i][j] < str[i - 1][j]) {
					str[i - 1].erase(j, str[i - 1].length() - j);
					break;
				}
			}
			if (str[i] < str[i - 1]) {
				str[i - 1].erase(str[i].length(), str[i - 1].length() - str[i].length());
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << "#" << str[i] << endl;
	}

	//fclose(fl);
	return 0;
}