#include <bits/stdc++.h>
using namespace std;
long long ans[10000005];
int main(int argc, char const *argv[]) {
	long long p; scanf("%lld", &p );
	memset(ans, -1, sizeof(ans));
	for (long long i = 0; i < p; i++) {
		long long temp = ((i % p) * i) % p;
		ans[temp] = i;
	}
	for (long long i = 0; i < p; ++i) {
		printf("%lld ", ans[i]);
	}
	return 0;
}
