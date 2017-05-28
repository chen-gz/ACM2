#include <bits/stdc++.h>
using namespace std;
struct fuck
{
	int index;
	int value;
	int ans;
} a[105];
// int a[105];
// int ans[105];
bool cmp(struct fuck a, struct fuck b) {
	return a.value < b.value;
}
bool cmp2(struct  fuck a, struct fuck b) {
	return a.index < b.index;
}
int main(int argc, char const *argv[]) {
	// FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	//       *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int n, w;
	cin >> n >> w;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].value;
		a[i].index = i;
	}
	sort(a, a + n, cmp);
	long long half = 0 ;
	long long all = 0 ;
	for (int i = 0; i < n; i++) {
		if (a[i].value % 2 == 0) {
			a[i].ans = a[i].value / 2;
			half += a[i].value / 2;
		}
		else half += a[i].value / 2 + 1, a[i].ans = a[i].value / 2 + 1;
		all += a[i].value;
	}
	if (all < w || half > w) {
		cout << -1 << endl;
		return 0;
	}
	else {
		w = w - half;
		int ac = n;
		while (w > 0) {
			if (w > a[ac].value - a[ac].ans) {
				w -= a[ac].value - a[ac].ans;
				a[ac].ans = a[ac].value;
			}
			else {
				a[ac].ans += w;
				break;
			}
			ac--;
		}
	}
	sort(a, a + n, cmp2);
	for (int i = 0; i < n; ++i) {
		cout << a[i].ans << " ";
	}
	cout << endl;
	return 0;
}