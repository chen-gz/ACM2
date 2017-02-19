#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	freopen("input.txt", "r", stdin);
	int suma, sumb, a1, a2, b1, b2;
	scanf("%d%d%d%d%d%d", &suma, &sumb, &a1, &a2, &b1, &b2);
	bool can = false ;
	if (a1 + b1 <= suma && a2 <= sumb && b2 <= sumb)
		can = true;
	if (a1 + b2 <= suma && a2 <= sumb && b1 <= sumb)
		can = true;
	if (a1 + b1 <= sumb && a2 <= suma && b2 <= suma)
		can = true;
	if (a1 + b2 <= sumb && a2 <= suma && b1 <= suma)
		can = true;
	if (a2 + b1 <= suma && a1 <= sumb && b2 <= sumb)
		can = true;
	if (a2 + b2 <= suma && a1 <= sumb && b1 <= sumb)
		can = true;
	if (a2 + b1 <= sumb && a1 <= suma && b2 <= suma)
		can = true;
	if (a2 + b2 <= sumb && a1 <= suma && b1 <= suma)
		can = true;

	if (can) {
		printf("YES\n");
	}
	else
		printf("NO\n");
	return 0;
}