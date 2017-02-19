//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//#define N 303
//using namespace std;
//
//int num[N][N];
//
//void whatthefuck() {
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			scanf("%d", &num[i][j]);
//		}
//	}
//	for (int k = 0; k < n; k++) {
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				if (num[i][j] > num[i][k] + num[k][j]) {
//					printf("-1\n");
//					return;
//				}
//			}
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (j == 0)
//				printf("%d", num[i][j]);
//			else
//				printf(" %d", num[i][j]);
//		}
//		printf("\n");
//	}
//	return;
//}
//
//int main() {
//	whatthefuck();
//	return 0;
//}