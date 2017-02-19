#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m, n;
	cin >> m >> n;
	if (m>n) swap(m, n);
	for(int i=m+1; i<=n+1; i++)
	{
		cout <<i<<endl;
	}
}
