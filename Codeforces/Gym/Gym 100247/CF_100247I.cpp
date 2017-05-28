//#include<iostream>
//#include<algorithm>
//#include<queue>
//#include<vector>
//#include<functional>
//#define ll long long 
//using namespace std;
//int main() {
//	priority_queue<int,vector<int>,less<int>> q;
//	ll dun = 0; ll ans = 0;
//	int n; cin >> n;
//	ll last = 0;
//	for (int i = 0; i < n; i++) {
//		ll t; ll d; cin >> t >> d;
//		dun = dun + t - last;
//		last = t;
//		if (dun >= d) {
//			dun -= d;
//			q.push(d);
//		}
//		else {
//			q.push(d);
//			dun += q.top();q.pop();
//			dun -= d;
//			ans++;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}