#include <bits/stdc++.h>
using namespace std;
struct node {
	string name;
	int score;
	int lastpos;
} player[1005];
map<string, int> mp;
map<string, int> acmp;
int cntplayer;
string name[1005];
int fuck[1005];
bool cmp(node a, node b) {
	return a.score > b.score;
}
int main() {
	FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	      *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	string str;
	int score;
	for (int i = 0; i < n; ++i) {
		cin >> str >> score;
		name[i] = str;
		fuck[i] = score;
		if (mp.find(str) != mp.end()) {
			player[mp[str]].score += score;
			player[mp[str]].lastpos = i;
		}
		else {
			mp[str] = cntplayer++ ;
			player[mp[str]].name = str;
			player[mp[str]].score += score;
			player[mp[str]].lastpos = i;
		}
	}
	sort(player, player + cntplayer, cmp);
	// for (int i = 0; i < cntplayer; ++i) {
	// 	cout << player[i].name << " " << player[i].score << " " << player[i].lastpos << endl;
	// }
	int ac = player[0].score;
	str = player[0].name;
	int lastpos = player[0].lastpos;
	for (int i = 0; i <= cntplayer; ++i) {
		if (player[i].score < ac ) {
			break;
		}
		else {
			acmp[player[i].name] = 0 ;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (acmp.find(name[i]) != acmp.end()) {
			acmp[name[i]] += fuck[i];
			if (acmp[name[i]] >= ac ) {
				cout << name[i] << endl;
				break;
			}
		}
	}
	// cout << acmp.size() << endl;
	// cout << str << endl;
}