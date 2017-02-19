//#include<iostream>
//#include<set>
//#include<string>
//#include<map>
//using namespace std;
//map<string, long long > mp1;
//int main() {
//	long long  n; cin >> n;
//	set<string> str;
//	for (long long  i = 0; i < n; i++) {
//		string tmp; cin >> tmp;
//		char index = 'A';
//		map<char, char> mp2;
//		mp2.clear();
//		set<char> ch;
//		ch.clear();
//		for (long long  j = 0; j < tmp.length(); j++) {
//			if (!ch.count(tmp[j])) {
//				ch.insert(tmp[j]);
//				mp2[tmp[j]] = index++;
//			}
//			tmp[j] = mp2[tmp[j]];
//		}
//		str.insert(tmp);
//		mp1[tmp]++;
//	}
//	long long ans = 0;
//	set<string>::iterator iter = str.begin();
//	for (; iter != str.end(); iter++) {
//		long long tmp = mp1[*iter];
//		if (tmp % 2 == 0) {
//			ans += tmp / 2 * (tmp - 1);
//		}
//		else ans += (tmp - 1) / 2 * tmp;
//	}
//	cout << ans << endl;
//	return 0;
//}