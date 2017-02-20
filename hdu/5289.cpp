//HDU 5289 Assignment
#include <stdio.h>
#include <string.h>
#define MAXN 100020

int mx[MAXN][20], mi[MAXN][20], mm[MAXN], n = 0;
int a[MAXN];

int max(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
	return a < b ? a : b; 
}

void init(){
	int i = 0, j = 0;
	mm[0] = -1;
	for(i = 1; i <= n; ++i){
		mm[i] = ((i & (i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
		mx[i][0] = a[i];
		mi[i][0] = a[i];
	}
	for(j = 1; j <= mm[n]; ++j){
		for(i = 1; i + (1 << j) - 1 <= n; ++i){
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
			mi[i][j] = min(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
		}
	}
	return;
}

int rmq(int x, int y){
	int k = mm[y - x + 1];
	return max(mx[x][k], mx[y - (1 << k) + 1][k]) - min(mi[x][k], mi[y - (1 << k) + 1][k]);
}

int main(){
	int T = 0, i = 0, j = 0;
	int m = 0, l = 0, r = 0, mid = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		for(i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		init();
		long long ans = 0;
		for(i = 1; i <= n; ++i){
			l = i;
			r = n;
			while(l <= r){
				mid = (l + r) >> 1;
				if(rmq(i, mid) < m)
					l = mid + 1;
				else
					r = mid - 1;
			}
			if(rmq(i, r) < m)
				ans += (r - i + 1);
			else
				ans += (l - i + 1);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
