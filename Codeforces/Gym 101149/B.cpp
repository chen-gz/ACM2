#include <cstdio>
#include <algorithm>
using namespace std;
struct node {
	int need, died;
};
node gg[200005];
bool cmp(node a, node b) {
	return a.need - a.died > b.need - b.died;
}
int main(int argc, char const *argv[]) {
	freopen("input.txt", "r", stdin);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &gg[i].need, &gg[i].died);
	}
	sort(gg, gg + n, cmp);
	long long rest = 0;
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		if (rest < gg[i].need) {
			cnt += gg[i].need - rest;
			rest = gg[i].need;
		}
		rest -= gg[i].died;
	}
	printf("%lld\n", cnt);
	return 0;
}
