#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
set<string> st;
string a[51];
int main(int argc, char const *argv[]) {
	// FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	//       *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	cin >> a[0];
	st.insert(a[0]);
	string tmp(a[0]);
	mp[a[0]] = 0;
	int len = 1;
	for (int i = 0; i < a[0].length() - 1; ++i) {
		char temp = a[0][i];
		tmp.erase(0, 1);
		tmp.push_back(temp);
		// cout << tmp << endl;
		if (st.count(tmp))
			continue;
		mp[tmp] = i + 1;
		st.insert(tmp);
		len++;
	}
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> a[i + 1];
	}
	int ans = 99999999;
	bool can = true;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		if (!can) break;
		for (int j = 0; j < n; j++) {
			if (st.count(a[j])) {
				if (mp[a[i]] == mp[a[j]]) continue;
				else if (mp[a[i]] < mp[a[j]]) {
					temp += len - mp[a[j]] + mp[a[i]];
					// 	cout << "NO" << endl;
					// 	cout << "tem" << endl;
					// 	cout << len << endl;
					// 	cout << mp[a[j]] << endl;
					// 	cout << mp[a[i]] << endl;
				}
				else {
					temp += mp[a[i]] - mp[a[j]];
					// cout << a[i] << endl;
					// cout << a[j] << endl;
					// cout << mp[a[i]] << endl;
					// cout << mp[a[j]] << endl;
				}
			}
			else {
				can = false;
				break;
			}
		}
		ans = min(ans, temp);
	}
	if (can) {
		cout << ans << endl;
	}
	else
		cout << -1 << endl;
	return 0;
}