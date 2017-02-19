//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<cstdio>
//using namespace std;
//int main() {
//	char str[10010];
//	while (~scanf("%s",str)) {
//		long long  a[1001];
//		int index = 0;
//		long long  tmp = 0;
//		for (int i = 0; i < strlen(str); i++) {
//			if (str[i] == '5') {
//				if (i == 0)
//					continue;
//				if (str[i - 1] == '5')
//					continue;
//				a[index++] = tmp;
//				tmp = 0;
//				continue;
//			}
//			if (tmp == 0 && str[i] == '0')
//				continue;
//			else {
//				tmp = tmp * 10 + str[i] - '0';
//			}
//		}
//		if (str[strlen(str) - 1]!='5')
//			a[index++] = tmp;
//		index--;
//		sort(a, a + index+1);
//		for (int i = 0; i < index; i++) {
//			cout << a[i] << " ";
//		}
//			cout << a[index] << endl;
//	}
//}