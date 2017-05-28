//#include<iostream>
//#include<algorithm>
//#include<set>
//#include<string>
//#include<cstdio>
//#include<vector>
//using namespace std;
//int a[2602][2602];
//int b[2602][2602];
//int main() {
//	int m, n; 
//	scanf("%d %d", &n, &m);
//	getchar();
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			char tmp;
//			scanf("%c", &tmp);
//			if (tmp == '#') {
//				b[i][j] = b[i - 1][j] + 1;
//				a[i][j] = a[i][j - 1] + 1;
//			}
//			else {
//				b[i][j] = b[i - 1][j];
//				a[i][j] = a[i][j - 1];
//			}
//		}
//		getchar();
//	}
//	int t;
//	cin >> t;
//	while (t--) {
//		int x1, y1, x2, y2;
//		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
//		if ((x1 - x2) * (y1 - y2) >= 0){
//			if (x1 < x2)	swap(x1, x2);
//			if (y1 < y2)	swap(y1, y2);
//			if ((b[x1][y1] - b[x2][y1] || a[x2][y1] - a[x2][y2]) && (b[x1][y2] - b[x2][y2] || a[x1][y1] - a[x1][y2])) puts("NO");
//			else puts("YES");
//		}
//		else{
//			if (y1 > y2){
//				swap(x1, x2);
//				swap(y1, y2);
//			}
//			if ((b[x1][y1] - b[x2][y1] || a[x2][y2] - a[x2][y1 - 1]) && (b[x1][y2] - b[x2][y2] || a[x1][y2] - a[x1][y1])) puts("NO");
//
//			else puts("YES");
//		}
//	}
//}
//
//
///*
//5 4
//.#..
//..#.
//#...
//..#.
//.#..
//7
//1 1 1 1
//2 2 4 2
//4 1 2 2
//1 3 5 4
//4 1 2 4
//1 3 3 2
//3 4 5 1
//*/