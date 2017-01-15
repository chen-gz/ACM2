//#include<cstring>
//#define maxn 555555
//int mark[maxn], prime[maxn], res;//prime�洢��������3��ʼ��mark[i]��ʾi����С������
//void get_prime(int n) {//��������ɸ�����õ�n��������������res��
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
