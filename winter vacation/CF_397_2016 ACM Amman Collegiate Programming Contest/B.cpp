#include <bits/stdc++.h>
int table[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main(int argc, char const *argv[]) {
	freopen("input.txt", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		string num; cin >> num;
		int sum = 0 ;
		for (int i = 0; i < n; i++) {
			sum += table[(int)num - '0'];
		}
		sum -= 2 * n;
		for (int i = 0 ; i < n - 1; i++) {
			if (sum > 4 * n) {

				printf("8");
				sum -= 5;
			}
			else if (sum >= 4) {
				printf("9");
				sum -= 4;
			}
			else if (sum >= 1) {
				printf("7");
				sum -= 1;
			}
		}
		switch (sum) {
		case 1:
			printf("7" );
			break;
		case 2:
			printf("4");
			break;
		case 3:
			printf("5");
			break;
		case 4:
			printf("9");
			break;
		case 5:
			printf("8");
			break;
		}
		printf("\n");
	}
	return 0;
}
