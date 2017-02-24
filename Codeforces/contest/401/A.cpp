#include <bits/stdc++.h>
using namespace std;
int ans[6][3] = {0, 1, 2, 1, 0, 2, 1, 2, 0, 2, 1, 0, 2, 0, 1, 0, 2, 1};
int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	//FILE *fl = freopen("input.txt", "r", stdin);
	int n; int k;
	cin >> n >> k;
	int ac = n % 6 ;
	cout << ans[ac][k] << endl;
	//fclose(fl);
	return 0;
}