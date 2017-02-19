#include <bits/stdc++.h>
int num[102];
int main(){
	int n, m, k;
	while(scanf("%d %d %d",&n, &m,&k)&&n) {
		for(int i=0; i<k; i++)
			scanf("%d", &num[i]);
		int sum = 0;
		for(int i=0; i<m; i++) {
			sum += n;
			n += num[i%k];
		}
		std::cout << sum << '\n';
	}
	return 0;
}
