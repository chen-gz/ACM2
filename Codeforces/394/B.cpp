#include <bits/stdc++.h>
using namespace std;
int a[50];
int b[50];
set<int> s;
int main(int argc, char const *argv[]) {
	freopen("input.txt", "r", stdin);
	int n,l;
	a[0]=-1;
	b[0]=-1;
	std::cin >> n >> l;
	bool flag = true;
	for(int i=1; i<=n; i++) {
		std::cin >> a[i];
		if(a[i]<=a[i-1] )
			flag = false;
		if(a[i]>l)
			flag = false;
	}
	for(int i=1; i<=n; i++) {
		std::cin >> a[i];
		if(a[i]<=a[i-1] )
			flag = false;
		if(a[i]>l)
			flag = false;
	}
	if(flag)
		std::cout << "YES" << '\n';
	else
		std::cout << "NO" << '\n';



	return 0;
}
