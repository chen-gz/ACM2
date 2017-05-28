//#include<iostream>
//#include<map>
//#include<vector>
//using namespace std;
//int main() {
//	int N, M;
//	cin >> N;
//	vector<int> A(N);
//	map<int, int> C;
//	for (int i = 0; i < N; i++) {
//		cin >> A[i];
//		C[A[i]] += 1;
//	}
//	if (C.size() == 1) {
//		cout << "0" << endl;
//		return 0;
//	}
//	cin >> M;
//	for (int i = 0; i < M; i++) {
//		int x, y;
//		cin >> x >> y;
//		x--;
//		C[A[x]] -= 1;
//		C[y] += 1;
//		A[x] = y;
//		if (C[y] == N) {
//			cout << i + 1 << endl;
//			return 0;
//		}
//	}
//	cout << "-1" << endl;
//	return 0;
//}