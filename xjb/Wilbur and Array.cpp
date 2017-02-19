//#include<iostream>
//#include<stdio.h>
//#include<cmath>
//using namespace std;
//long long a[200010];
//int main() {
//	int n; cin >> n;
//	long long ans = 0;
//	int index = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	int last = 0;
//	int now = 0;
//	for (int i = 0; i < n; i++) {
//		now = a[i];
//		if (now == last) {
//			continue;
//		}
//		else {
//			ans += abs(now - last);
//			last = now;
//		}
//	}
//	cout << ans << endl;
//}