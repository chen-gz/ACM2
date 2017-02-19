//#include<iostream>
//#include<vector>
//#include<algorithm>
//#define pi 3.14159265359
//using namespace std;
//
//int main() {
//	int N;
//	long long M;
//	cin >> N >> M;
//	if (M == 0) {
//		cout << 0 << endl;
//		return 0;
//	}
//	vector<long long> A(N), B(N);
//	for (int i = 0; i < N; i++)
//		cin >> A[i];
//	for (int i = 0; i < N; i++)
//		cin >> B[i];
//	long long Cmin = 0, Cmax = 1000000000 + 42;
//	while (Cmax - Cmin > 1) {
//		long long C = (Cmin + Cmax) / 2, m = 0;
//		for (int i = 0; i < N; i++) if (A[i] >= C) {
//			long long k = (A[i] - C) / B[i] + 1;
//			m += k;
//		}
//		if (m < M)
//			Cmax = C;
//		else
//			Cmin = C;
//	}
//	long long ans = 0, m = 0;
//	for (int i = 0; i < N; i++)
//		if (A[i] >= Cmax) {
//			long long k = (A[i] - Cmax) / B[i] + 1;
//			m += k;
//			ans += 1LL * k*A[i] - B[i] * 1LL * k*(k - 1) / 2;
//		}
//	ans += (M - m)*max(1LL, Cmin);
//	cout << ans << "\n";
//	return 0;
//}