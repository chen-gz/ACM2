#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	freopen("input.txt","r",stdin);
	int n; scanf("%d\n", &n);
	int last=0;
	long long ans =0;
	for(int i=0; i<n; i++) {
		int now;
		scanf("%d", &now);
		if(now>last) {
			ans+=now-last;
		}
		last = now;
	}
	cout<<ans;
	return 0;
}
