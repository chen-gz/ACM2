//#include<iostream>
//#include<vector>
//#include<set>
//#define pi 3.14159265359
//using namespace std;
//
//int main() {
//	int N;
//	cin >> N;
//	int a = (N + 1) / 2;
//	if (N == 1) {
//		cout << "A 1\n"; 
//		return 0; 
//	}
//	cout << "Q 1 " << a << endl;
//	cout.flush();
//	vector<int> S(N + 42, 0);
//	set<int> s;
//	for (int i = 0; i < a; i++) {
//		int x;
//		cin >> x;
//		S[0] += x;
//		s.insert(x);
//	}
//	if (N == 2) {
//		cout << "A " << *s.begin() << " " << 3 - *s.begin() << endl;
//		return 0;
//	}
//	vector<int> ans(N);
//	for (int i = 0; i < a - 1; i++) {
//		cout << "Q " << i + 2 << " " << i + 1 + a << endl;
//		cout.flush();
//		set<int> s2;
//		for (int j = 0; j < a; j++) {
//			int x;
//			cin >> x;
//			S[i + 1] += x;
//			s2.insert(x);
//			if (s.find(x) == s.end()) ans[i + a] = x;
//		}
//		for (auto it = s.begin(); it != s.end(); it++) if (s2.find(*it) == s2.end())
//			ans[i] = *it;
//		s = s2;
//	}
//	for (int i = 0; i < N - a; i++) if (ans[i + a - 1] == 0) {
//		for (int j = 0; j < a; j++) S[i] -= ans[i + j];
//		ans[i + a - 1] = S[i];
//	}
//	if (ans[N - 1] == 0) {
//		long long x = N*(N + 1) / 2;
//		for (int i = 0; i < N - 1; i++) x -= ans[i];
//		ans[N - 1] = x;
//	}
//	cout << "A ";
//	for (int i = 0; i < N; i++) cout << ans[i] << ((i == N - 1) ? "\n" : " ");
//	return 0;
//}