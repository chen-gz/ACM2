//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include<string>
//#include<iostream>
//using namespace std;
//int map[4][4];
//int main() {
//	for (int i = 0; i < 4; i++) {
//		string s;
//		cin >> s;
//		for (int j = 0; j < 4; j++) {
//			if (s[j] == 'x') {
//				map[i][j] = 1;
//			}
//			else if (s[j] == 'o') {
//				map[i][j] = 2;
//			}
//		}
//	}
//	bool flag = false;
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			if (map[i][j] == 1) {
//				if (i - 1 >= 0 && i + 1 <= 3 && j - 1 >= 0 && j + 1 <= 3) {
//					if (map[i - 1][j - 1] == 0 && map[i + 1][j + 1] == 1) {
//						flag = true;
//					}
//					if (map[i - 1][j - 1] == 1 && map[i + 1][j + 1] == 0) {
//						flag = true;
//					}
//					if (map[i + 1][j - 1] == 1 && map[i - 1][j + 1] == 0) {
//						flag = true;
//					}
//					if (map[i - 1][j + 1] == 1 && map[i + 1][j - 1] == 0) {
//						flag = true;
//					}
//				}
//				if (i - 1 >= 0 && i + 1 <= 3) {
//					if (map[i - 1][j] == 0 && map[i + 1][j] == 1) {
//						flag = true;
//					}
//					if (map[i + 1][j] == 0 && map[i - 1][j] == 1) {
//						flag = true;
//					}
//				}
//				if (j - 1 >= 0 && j + 1 <= 3) {
//					if (map[i][j - 1] == 0 && map[i][j + 1] == 1) {
//						flag = true;
//					}
//					if (map[i][j + 1] == 0 && map[i][j - 1] == 1) {
//						flag = true;
//					}
//				}
//			}
//			if (map[i][j] == 0) {
//				if (i - 1 >= 0 && i + 1 <= 3 && j - 1 >= 0 && j + 1 <= 3) {
//					if (map[i - 1][j - 1] == 1 && map[i + 1][j + 1] == 1) {
//						flag = true;
//					}
//					if (map[i + 1][j - 1] == 1 && map[i - 1][j + 1] == 1) {
//						flag = true;
//					}
//				}
//				if (i - 1 >= 0 && i + 1 <= 3) {
//					if (map[i - 1][j] == 1 && map[i + 1][j] == 1) {
//						flag = true;
//					}
//					if (map[i + 1][j] == 1 && map[i - 1][j] == 1) {
//						flag = true;
//					}
//				}
//				if (j - 1 >= 0 && j + 1 <= 3) {
//					if (map[i][j - 1] == 1 && map[i][j + 1] == 1) {
//						flag = true;
//					}
//					if (map[i][j + 1] == 1 && map[i][j - 1] == 1) {
//						flag = true;
//					}
//				}
//				
//			}
//
//		}
//	}
//	if (flag) {
//		cout << "YES" << endl;
//	}
//	else
//		cout << "NO" << endl;
//}