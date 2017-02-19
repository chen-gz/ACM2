//#include<iostream>
//#include<algorithm>
//using namespace std;
//int a[1001];
//int main() {
//	int n; cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	sort(a, a + n);
//	int ans = 0;
//	int last=a[0];
//	for (int i = 0; i < n; i++) {
//		int cnt = 0;
//		while(last == a[i]) {
//			cnt++;
//			i++;
//		}
//		//count
//		last = a[i];
//		if (ans < cnt)
//			ans = cnt;
//		i--;
//	}
//	cout << n - ans << endl;
//
//	return 0;
//}