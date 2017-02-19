#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define ll long long
using namespace std;
const int INF = 100000000;
char a[100005];
int main() {
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", a);
		int book[30];
		memset(book, 0, sizeof(book));
		int len = strlen(a);
		int tol = 0;
		char u = 0, v = 0;
		for (int i = 0; i < len; i++) {
			if (!book[a[i] - 97]) {
				book[a[i] - 97] = ++tol;
			}
		}
		int num = 1;
		for (int i = 0; i <= 25; i++) {
			if (book[i] >= 1) {
				if (book[i] == num) {
					num++;
				}
				else {
					u = i + 97;
					for (int j = 0; j <= 25; j++) {
						if (book[j] == num) {
							v = j + 97;
							break;
						}
					}
					break;
				}
			}

		}
		for (int i = 0; i < len; i++) {
			if (a[i] == u && u > 0)
				printf("%c", v);
			else if (a[i] == v && v > 0)
				printf("%c", u);
			else printf("%c", a[i]);
		}
		printf("\n");
	}
	return 0;
}