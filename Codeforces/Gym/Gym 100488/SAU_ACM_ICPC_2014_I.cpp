//#include<iostream>
//#include<algorithm>
//#include<map>
//#include<cstdio>
//#include<functional>
//#include<vector>
//#define pi 3.14159265359
//using namespace std;
//
//int main() {
//	int N, M, K;
//	cin >> N >> M >> K;
//	vector< vector<int> > G(N, vector<int>(N, 0));
//	for (int i = 0; i < M; i++) {
//		int a, b;
//		cin >> a >> b;
//		G[--a][--b]++;
//		G[b][a]++;
//	}
//	vector<int> part(N, -1);
//	map<int, int> m;
//	 
//	for (int i = 0; i < N; i++)
//		if (part[i] == -1) {
//			part[i] = i;
//			m[i] = 0;
//			for (int j = i + 1; j < N; j++)
//				if (G[i][j] == 0) {
//					if (part[j] != -1) {
//						cout << "-1\n";
//						return 0;
//					}
//					part[j] = i;
//				}
//		}
//		else if (G[part[i]] != G[i]) {
//			cout << "-1\n";
//			return 0;
//		}
//
//		int a = 0;
//		for (auto it = m.begin(); it != m.end(); it++)
//			it->second = a++;
//		if (m.size() > K) {
//			cout << "-1\n";
//			return 0;
//		}
//		vector<int> ans(N);
//		for (int i = 0; i < N; i++)
//			cout << m[part[i]] + 1 << ((i == N - 1) ? "\n" : " ");
//		return 0;
//}