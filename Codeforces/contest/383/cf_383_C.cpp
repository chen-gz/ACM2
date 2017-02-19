//#include<iostream>
//#include<algorithm>
//#include<set>
//using namespace std;
//#define ll long long 
//ll a[200];
//int main() {
//	int n;
//	cin >> n;
//	int ans = 0;
//	set<int> have;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		have.insert(i);
//	}
//	set<int> s;
//	s.insert(1);
//	int now = 1;
//	have.erase(1);
//	int tmp = 0;
//	while (!have.empty()) {
//		if (s.count(now)) {
//			//Ñ°ÕÒÏÂÒ»¸ö£»
//			ans += tmp;
//			tmp = 0;
//			for (int i = 1; i <= n; i++) {
//				if (have.count(i)) {
//					now = i;
//					break;
//				}
//			}
//		}
//		else if (have.count(a[now])) {
//			now = a[now];
//			have.erase(a[now]);
//			s.insert(a[now]);
//			tmp++;
//		}
//	}
//	cout << ans << endl;
//}