#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
void solve() {
	int n;
	cin >> n;
	vector<string> names(n);
	for (string& name : names) {
		cin >> name;
	}
	sort(all(names));

	auto getIdx = [&](const string& s) {
					  int pos = lower_bound(all(names), s) - names.begin();
					  if (pos == (int)names.size() || names[pos] != s)
						  return -1;
					  return pos;
				  };

	auto splitIntoUserMessage = [](const string& s) {
									size_t pos = s.find(':');
									assert(pos != string::npos);
									return make_pair(s.substr(0, pos), s.substr(pos + 1));
								};

	auto splitIntoTokensOfLatinLetters = [](const string& s) {
											 vector<string> result;
											 string token;
											 for (char c : s) {
												 if (isalpha(c) || isdigit(c)) {
													 token += c;
												 }
												 else {
													 if (!token.empty()) {
														 result.push_back(token);
													 }
													 token.clear();
												 }
											 }
											 if (!token.empty()) {
												 result.push_back(token);
											 }
											 return result;
										 };

	int m;
	cin >> m;
	vector<int> who(m);
	vector< vector<char> > can(m, vector<char>(n, true));

	vector<string> messages(m);

	string tmp;
	getline(cin, tmp);

	for (int i = 0; i < m; i++) {
		string cur;
		getline(cin, cur);
		pair<string, string> p = splitIntoUserMessage(cur);
		const string& user = p.first;
		const string& message = p.second;
		who[i] = getIdx(user);
		if (who[i] != -1) {
			fill(all(can[i]), false);
			can[i][who[i]] = true;
		}
		messages[i] = message;
		vector<string> tokens = splitIntoTokensOfLatinLetters(message);
		for (const string& z : tokens) {
			int idx = getIdx(z);
			if (idx != -1) {
				can[i][idx] = false;
			}
		}
	}

	vector<vector<int> > par(m, vector<int>(n, -1));
	for (int i = 0; i < n; i++) {
		if (can[0][i])
			par[0][i] = 0;
	}
	//还没看懂。。
	for (int msg = 0; msg + 1 < m; msg++) {
		for (int i = 0; i < n; i++) {
			if (par[msg][i] == -1)
				continue;
			for (int j = 0; j < n; j++) {
				if (i == j)
					continue;
				if (can[msg + 1][j]) {
					par[msg + 1][j] = i;
				}
			}
		}
	}
	int msg = m - 1, pos = -1;
	for (int i = 0; i < n; i++) {
		if (par[msg][i] != -1) {
			pos = i;
			break;
		}
	}
	if (pos == -1) {
		cout << "Impossible\n";
		return;
	}
	while (msg >= 0) {
		who[msg] = pos;
		pos = par[msg][pos];
		msg--;
	}
	for (int i = 0; i < m; i++) {
		cout << names[who[i]] << ":" << messages[i] << "\n";
	}
	return;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t; // number of tests

	while (t--) {
		solve();
	}
}
