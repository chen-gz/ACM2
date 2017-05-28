//#include<iostream>
//#include<cstdio>
//#include<string>
//#include<queue>
//
//#define pi 3.14159265359
//using namespace std;
//
//int main() {
//	int N, L, R, M;
//	string s;
//	cin >> N >> L >> R >> s >> M;
//	L--, R--;
//	deque<char> Dl, Dr, Dc;
//	for (int i = 0; i < L; i++) Dl.push_back(s[i]);
//	for (int i = L; i <= R; i++) Dc.push_back(s[i]);
//	for (int i = R + 1; i < s.length(); i++) Dr.push_back(s[i]);
//	bool inv = false;
//	for (int i = 0; i < M; i++) {
//		string t, s1, s2;
//		cin >> t;
//		if (t == "Q") {
//			cin >> s1;
//			if ((s1 == "L") ^ inv) cout << Dc.front();
//			else cout << Dc.back();
//			continue;
//		}
//		if (t == "S") {
//			cin >> s1 >> s2;
//			if (!inv) {
//				if (s1 == "L") {
//					if (s2 == "L") {
//						Dc.push_front(Dl.back());
//						Dl.pop_back();
//					}
//					else {
//						Dl.push_back(Dc.front());
//						Dc.pop_front();
//					}
//				}
//				else {
//					if (s2 == "L") {
//						Dr.push_front(Dc.back());
//						Dc.pop_back();
//					}
//					else {
//						Dc.push_back(Dr.front());
//						Dr.pop_front();
//					}
//				}
//			}
//			else {
//				if (s1 == "L") {
//					if (s2 == "L") {
//						Dc.push_back(Dl.back());
//						Dl.pop_back();
//					}
//					else {
//						Dl.push_back(Dc.back());
//						Dc.pop_back();
//					}
//				}
//				else {
//					if (s2 == "L") {
//						Dr.push_front(Dc.front());
//						Dc.pop_front();
//					}
//					else {
//						Dc.push_front(Dr.front());
//						Dr.pop_front();
//					}
//				}
//			}
//			continue;
//		}
//		inv = 1 - inv;
//	}
//	return 0;
//}