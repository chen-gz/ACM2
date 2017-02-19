///*
//B
//*/
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int map[1001][1001];
//int dp_row[1001][1001];
//int dp_colum[1001][1001];
//int main() {
//	int n, m; cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> map[i][j];
//			if (map[i][j] == 0) {
//				dp_row[i][j] = dp_row[i][j - 1];
//				dp_colum[i][j] = dp_colum[i-1][j];
//			}
//			else {
//				dp_row[i][j] = dp_row[i][j-1]+1;
//				dp_colum[i][j] = dp_colum[i-1][j]+1;
//			}
//		}
//	}
//	int ans = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (map[i][j] == 0) {
//				if (dp_row[i][j] >= dp_row[i][0] && dp_row[i][j]!=0)
//					ans++;
//				if (dp_row[i][j] < dp_row[i][m-1])
//					ans++;
//				if (dp_colum[i][j] >= dp_colum[0][j] && dp_colum[i][j] != 0)
//					ans++;
//				if (dp_colum[i][j] < dp_colum[n-1][j])
//					ans++;
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}