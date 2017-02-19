#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[200005];
int same[200005];
int ac;
int main(int argc, char const *argv[]) {
	freopen("input.txt", "r", stdin);
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == i) {
			same[ac++] = i;
		}
	}
	int cnt = 0;
	printf("%d\n", ac / 2 + (bool)(ac & 1));
	for (int i = 0; i < ac  ; i ++) {
		printf("%d ", same[i]);
		if (cnt == 1) {
			cnt = 0;
			printf("\n");
		}
		else
			cnt++;
	}
	if (ac & 1)
		printf("%d\n", same[ac - 1] - 1 == 0 ? a[same[ac - 1] + 1] : a[same[ac - 1] - 1]);
	return 0;
}