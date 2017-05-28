//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<queue>
//#include<string>
//using namespace std;
//int main() {
//	long long k2, k3, k5, k6;
//	cin >> k2 >> k3 >> k5 >> k6;
//	k5 = min(k5, k6);
//	int ans = 0;
//	if (k2 >= k5) {
//		k2 -= k5;
//		ans += 256 * k5;
//	}
//	else if (k2 <= k5) {
//		ans += k2 * 256;
//		k2 = 0;
//	}
//	if (k2 >= k3) {
//		ans += k3 * 32;
//	}
//	else ans += k2 * 32;
//	cout << ans << endl;
//}