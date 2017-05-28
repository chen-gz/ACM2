//#include<iostream>
//#include<string>
//
//#define pi 3.14159265359
//using namespace std;
//
//string solve(int K, int z, bool down) {
//	if (K == 0) return "";
//	for (int i = 1; i <= 100000; i++) {
//		if (1LL * i*(i + 1) / 2 > 1LL * K) break;
//		if (1LL * i*(i + 1) / 2 + (down ? -i / 2 : 0) == 1LL * K) {
//			string ret;
//			for (int j = 0; j < i; j++) ret += ('a' + z);
//			return ret;
//		}
//	}
//	for (int i = 1; i <= 100000; i++)
//		if (1LL * i*(i + 1) / 2 + (down ? (i - 1) / 2 : i / 2) - (down ? i / 2 : 0) + 1 <= K && 1LL * (i + 1)*(i + 2) / 2 + (down ? i / 2 : (i + 1) / 2) - (down ? (i + 1) / 2 : 0) + 1 > K) {
//			string ret;
//			for (int j = 0; j < i; j++) ret += ('a' + z);
//			ret += ('a' + z + 1);
//			ret += solve(K - 1LL * i*(i + 1) / 2 - (down ? (i - 1) / 2 : i / 2) + (down ? i / 2 : 0) - 1, z + 3, true);
//			if (ret.length() > i + 1) ret[i + 1] = ('a' + z + 2);
//			return ret;
//		}
//}
//
//int main() {
//	int K;
//	cin >> K;
//	cout << solve(K, 0, false) << endl;
//	return 0;
//}