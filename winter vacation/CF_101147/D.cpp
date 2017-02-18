#include <iostream>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>

#include <algorithm>
#include <functional>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const int  INF = 0x3f3f3f3f;
const ll  LLINF = 0x3f3f3f3f3f3f3f3f;

/* real code start */

#define MAXN 25

int num[MAXN + 1][MAXN + 1];

void get_C(int n)//求<=n的组合数，模c
{
	for (int i = 0; i <= n; i++)
	{
		num[i][i] = 1;
		num[i][0] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			num[i][j] = (num[i - 1][j] + num[i - 1][j - 1]);
		}
	}
}

int main()
{
	freopen("popcorn.in", "r", stdin);
	int T;
	cin >> T;
	int a, b;
	get_C(20);
	while (T--)
	{
		scanf("%d %d", &a,&b);
		printf("%d\n", num[a][b]);
	}

	return 0;
}
