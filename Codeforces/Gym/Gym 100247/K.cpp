//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<string>
//#include<queue>
//using namespace std;
//#define readn(x) scanf("%d", &x)
//#define reads(x) scanf("%s",x)
//#define print(x) printf("%d ",x)
//int main() {
//	int left = 0;
//	int right = 0;
//	bool flag = true;
//	string s;
//	cin >> s;
//	for (int i = 0; i < s.length(); i++) {
//		left += (s[i] == '(');
//		right += (s[i] == ')');
//		if (left < right) {
//			flag = false;
//			break;
//		}
//	}
//	if (flag) {
//		cout << s;
//		for (int i = 0; i < left - right; i++) {
//			printf(")");
//		}
//		cout << endl;
//	}
//	else {
//		cout << "IMPOSSIBLE" << endl;
//	}
//	return 0;
//}