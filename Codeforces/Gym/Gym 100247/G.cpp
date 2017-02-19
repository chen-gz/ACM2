//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//#define N 200003
//using namespace std;
//
//char str[N];
//bool judge1[N], judge2[N];
//
//void whatthefuck() {
//	scanf("%s", str);
//	int len = strlen(str);
//	if (len > 26) {
//		printf("IMPOSSIBLE\n");
//		return;
//	}
//	for (int i = 0; i < len; i++) {
//		judge1[str[i]] = 1;
//	}
//	char a = 'a';
//	for (int i = 0; i < len; i++) {
//		if (judge2[str[i]] == 0)
//			judge2[str[i]] = 1;
//		else {
//			while (judge1[a])
//				a++;
//			str[i] = a;
//			a++;
//		}
//	}
//	printf("%s\n", str);
//	return;
//}
//
//int main() {
//	whatthefuck();
//	return 0;
//}