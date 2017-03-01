#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <bits/stdc++.h>
#include <ext/hash_map>
using namespace std;
string str[5005][5];
unordered_map<string, stack<int> > mp;
unordered_map<string, stack<int> > mp2;
int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> str[i][0] >> tmp >> str[i][2];
		if (str[i][2][0] != '0' && str[i][2][0] != '1') {
			str[i][1] = "0";
			cin >> str[i][3] >> str[i][4];
		}
		else
			str[i][1] = "1";
	}
	string ans1, ans2;
	for (int i = 0; i < m; i++) {
		int cnt0 = 0, cnt1 = 0;
		mp["?"].push(1);
		mp2["?"].push(0);
		cnt0 = 0, cnt1 = 0;
		for (int j = 0; j < n; j++) {
			if (str[j][1] == "1") {
				mp[str[j][0]].push( (int)str[j][2][i] - '0');
				mp2[str[j][0]].push( (int)str[j][2][i] - '0');
			}
			else {
				if (str[j][3][0] == 'X') {
					mp2[str[j][0]].push( mp2[str[j][2]].top() ^ mp2[str[j][4]].top());
					mp[str[j][0]].push( mp[str[j][2]].top() ^ mp[str[j][4]].top());
				}
				if (str[j][3][0] == 'O') {
					mp2[str[j][0]].push( mp2[str[j][2]].top() | mp2[str[j][4]].top());
					mp[str[j][0]].push( mp[str[j][2]].top() | mp[str[j][4]].top());
				}
				if (str[j][3][0] == 'A') {
					mp2[str[j][0]].push( mp2[str[j][2]].top() & mp2[str[j][4]].top());
					mp[str[j][0]].push( mp[str[j][2]].top() & mp[str[j][4]].top());
				}

			}
			if (mp[str[j][0]].top() == 1) {
				cnt1++;
			}
			if (mp2[str[j][0]].top() == 1) {
				cnt0++;
			}
		}
		if (cnt1 < cnt0) {
			ans1.push_back('1');
			ans2.push_back('0');
		}
		else if (cnt1 > cnt0) {
			ans1.push_back('0');
			ans2.push_back('1');
		}
		else {
			ans1.push_back('0');
			ans2.push_back('0');
		}
	}
	cout << ans1 << endl << ans2 << endl;
	return 0;
}