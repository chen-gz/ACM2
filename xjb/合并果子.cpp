// #include<iostream>
// #include<queue>
// #include<vector>
// #include<functional>
// using namespace std;
//
// int main() {
// 	priority_queue<int, vector<int>, greater<int>> q;
// 	int T; cin >> T;
// 	while (T--) {
// 		int ans = 0;
// 		int n; cin >> n;
// 		for (int i = 0; i < n; i++) {
// 			int tmp; cin >> tmp;
// 			q.push(tmp);
// 		}
// 		while (q.size() != 1) {
// 			int a = q.top(); q.pop();
// 			int b = q.top(); q.pop();
// 			ans += a + b;
// 			q.push(a + b);
// 		}
// 		cout << ans << endl;
// 		while (!q.empty()) q.pop();
//
// 	}
// }
