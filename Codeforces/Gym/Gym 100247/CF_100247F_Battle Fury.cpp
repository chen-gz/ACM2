//#include<iostream>
//#include<algorithm>
//using namespace std;
//#define ll long long
//ll n, p, q, a[2000010];
//ll len;
//bool judge(ll m) {
//	ll tmp = m * q;
//	ll i = 0;
//	while (i < n && a[i] <= tmp)
//		i++;
//	for (; i<n; i++)
//		m -= ((a[i]-tmp) / len + ((a[i]-tmp)%len != 0));
//	if (m < 0)
//		return false;
//	return true;
//}
//
//int main() {
//	ll mid, l = 0, r = 0xffffffff;
//	cin >> n >> p >> q;
//	len = p - q;
//	for (ll i = 0; i < n; i++) cin >> a[i];
//	sort(a, a + n);
//	if (len == 0) {
//		cout << a[n - 1] / q + (a[n - 1] % q != 0) << endl;
//		return 0;
//	}
//	while (r - l > 1) {
//		mid = (l + r) / 2;
//		if (judge(mid))	r = mid;
//		else	l = mid;
//	}
//	cout << r << endl;
//	return 0;
//}