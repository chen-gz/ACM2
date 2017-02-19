//#include<cstring>
//#define maxn 555555
//int mark[maxn], prime[maxn], res;//prime存储素数，从3开始，mark[i]表示i的最小素因素
//void get_prime(int n) {//素数线性筛法，得到n以内所有素数共res个
//	memset(mark, 0, sizeof(mark));
//	res = 0;
//	for (int i = 2; i <= n; i++) {
//		if (!mark[i])
//			mark[i] = prime[res++] = i;
//		for (int j = 0; j < res && prime[j] * i <= n; j++) {
//			mark[i*prime[j]] = prime[j];
//			if (i%prime[j] == 0)
//				break;
//		}
//	}
//}