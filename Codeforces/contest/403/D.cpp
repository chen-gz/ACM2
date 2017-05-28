#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
string str1, str2, name[N];
string nick[N];
string ans[N];
bool repeat[N];
queue<int> 	q;
bool done[N];
std::vector<int> RunTimeError[N];
int main(int argc, char const *argv[]) {
	FILE *fr = freopen("/home/pocky/Program/in", "r", stdin),
	      *fo = freopen("/home/pocky/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> str1 >> str2;
		name[i] += str1[0];
		name[i] += str1[1];
		name[i] += str1[2];
		nick[i] += str1[0];
		nick[i] += str1[1];
		nick[i] += str2[0];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j)
				continue;
			if (name[i] == name[j]) {
				repeat[i] = repeat[j] = true;
			}
			if (nick[i] == name[j]) {
				RunTimeError[i].push_back(j);
			}
		}

	}
	for (int i = 0; i < n; ++i) {
		if (repeat[i] == true) {
			ans[i] = nick[i];
			done[i] = true;
			q.push(i);
		}
		else ans[i] = name[i];
	}
	while (!q.empty()) {
		int ac = q.front(); q.pop();
		for (int i = 0; i < RunTimeError[ac].size(); ++i) {
			if (done[RunTimeError[ac][i]])
				continue;
			ans[RunTimeError[ac][i]] = nick[RunTimeError[ac][i]];
			q.push(RunTimeError[ac][i]);
			done[RunTimeError[ac][i]] = true;
		}
	}
	bool ac  = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j)continue;
			if (ans[i] == ans[j]) {
				ac = false;
			}
		}
	}
	if (ac ) {
		cout << "YES" << "\n";
		for (int i = 0; i < n; ++i) {
			cout << ans[i] << "\n";
		}
	}
	else cout << "NO\n";
	cout << endl;
	fclose(fr); fclose(fo);
}