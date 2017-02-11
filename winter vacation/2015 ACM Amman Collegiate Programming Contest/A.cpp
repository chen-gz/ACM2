#include <bits/stdc++.h>
using namespace std;
struct node
{
	char na[30];
	int n, m;
} num[105];

int cmp(const void *a, const void *b)
{
	if (((struct node*)a)->n == ((struct node*)b)->n)
	{
		return ((struct node*)a)->m - ((struct node*)b)->m;
	}
	else
	{
		return ((struct node*)b)->n - ((struct node*)a)->n;
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			scanf("%s %d %d", num[i].na, &num[i].n, &num[i].m);
		}
		qsort(num, n, sizeof(struct node), cmp);
		puts(num[0].na);
	}

	return 0;
}
