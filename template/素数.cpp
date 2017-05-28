#include <cstring>
#define maxn 555555
//素数保存在prime数组
int mark[maxn], prime[maxn], res;
void get_prime(int n) {
	//从2----n的素数
	memset(mark, 0, sizeof(mark));
	res = 0;
	for (int i = 2; i <= n; i++) {
		if (!mark[i])
			mark[i] = prime[res++] = i;
		for (int j = 0; j < res && prime[j] * i <= n; j++) {
			mark[i*prime[j]] = prime[j];
			if (i%prime[j] == 0)
				break;
		}
	}
}
