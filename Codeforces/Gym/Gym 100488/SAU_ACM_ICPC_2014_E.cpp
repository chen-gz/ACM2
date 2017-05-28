//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main() {
//	string s;
//	cin >> s;
//	if (s.length() % 2 != 0) {
//		cout << "NO" << endl;
//		return 0;
//	}
//	vector<int> P(26, 0);
//	for (int i = 0; i < s.length(); i++)
//		P[s[i] - 'a']++;
//	sort(P.begin(), P.end());
//	cout << ((P[25] * 2 <= s.length()) ? "YES\n" : "NO\n");
//	return 0;
//}