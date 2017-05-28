#include <bits/stdc++.h>
using namespace std;
std::vector<int> a;
int main(int argc, char const *argv[]) {
	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		a.clear();
		int n; scanf("%d", &n);
		int num; cin >> num;
		for (int i = 0; i<n; i++) {
			int tmp;
			scanf("%d", &tmp);
			a.push_back(tmp);
		}
		sort(a.begin(), a.end());
		int x, y;
		bool find = false;
		for (int i = 0; i<n; i++) {
			x = a[i];
			if(x==0)
				continue;
			if (num%x == 0) {
				y = num / x;
				auto index = lower_bound(a.begin(), a.end(), y);
				if(index == a.end())
					continue;
				if (*index == y && y !=x) {
					find = true;
					break;
				}
				index++;
				if (index!=a.end()&&*index == y) {
					find = true;
					break;
				}
			}
		}
		if (find) {
			printf("%d %d\n", x, y);
		}
		else
			printf("-1\n");
	}
	return 0;
}
