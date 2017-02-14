#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	freopen("input.txt", "r", stdin);
	int n; scanf("%d", &n);
	int max = -1;
	for (int i = 0; i < n; i++) {
		int temp; scanf("%d", &temp);
		if (max < temp) {
			max = temp;
		}
	}
	printf("%d\n", max);
	return 0;
}
