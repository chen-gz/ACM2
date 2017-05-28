//#include<iostream>
//#include<vector>
//using namespace std;
//vector < pair<long long, long long > > GG;
//long long n;
//long long judge(long long m);
//int main() {
//	cin >> n;
//	bool flag = true;
//	long long t, tt;
//	for (long long i = 0; i < n; i++) {
//		scanf("%I64d %I64d", &t, &tt);
//		if (tt == 2)
//			flag = false;
//		GG.push_back(pair<long long , long long >(t, tt));
//	}
//	if (flag) {
//		cout << "Infinity" << endl;
//		return 0;
//	}
//	long long l, r;
//	if (GG[0].second == 2) {
//		l = -2000000000, r = 1989;
//	}
//	else {
//		l = 1900, r = 200000000;
//	}
//	while (r - l > 1) {
//		long long m = (l + r) / 2;
//		if (judge(m) == 0 || judge(m) == -1) {
//			l = m;
//		}
//		else if (judge(m) == 1) {
//			r = m;
//		}
//	}
//	if (judge(r) == 0) {
//		//cout << r << endl;
//		for (long long i = 0; i < n; i++) {
//			r += GG[i].first;
//		}
//		cout << r << endl;
//	}
//
//	else if (judge(l) == 0) {
//		//cout << l << endl;
//		for (long long i = 0; i < n; i++) {
//			l += GG[i].first;
//		}
//		cout << l << endl;
//	}
//	else
//		cout << "Impossible" << endl;
//
//
//}
//long long judge(long long m) {
//	for (long long i = 0; i < n; i++) {
//		if (GG[i].second == 1 && m < 1900)
//			return -1;//小了
//		if (GG[i].second == 2 && m >= 1900)
//			return 1;//大了
//		m += GG[i].first;
//	}
//	return 0;
//}
