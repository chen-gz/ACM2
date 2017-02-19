#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;

const int MAXN = 200001;
int f[MAXN];
int a[MAXN], ac = 0;
int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> f[i];
	for (int i = 1; i <= n; i++) {
		if (f[f[i]] != f[i])
		{
			cout << -1 << endl;
			return 0;
		}
		if (f[i] == i)
			a[ac++] = i;
	}
	sort(a, a + ac);
	cout << ac << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << lower_bound(a, a + ac, f[i]) - a + 1 << " ";
	}
	cout << endl;
	for (int i = 0; i < ac; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
