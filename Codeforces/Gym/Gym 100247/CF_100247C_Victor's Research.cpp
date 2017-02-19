//#include<iostream>
//#include <algorithm>
//#include <map>
//using namespace std;
//long long  sum[2000001];
//map<long long, int> mp;
//int main(){
//	int n;
//	long long s;
//	cin >> n >> s;
//	sum[0] = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> sum[i];
//		sum[i] += sum[i - 1];
//	}
//	mp.clear();
//	long long ans = 0;
//	for (int i = 0; i <= n; i++) {
//		ans += mp[sum[i] - s];
//		mp[sum[i]]++;
//	}
//	cout << ans << endl;
//	return 0;
//}