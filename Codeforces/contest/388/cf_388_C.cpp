//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<queue>
//#include<deque>
//using namespace std;
//int main() {
//	int n;
//	cin >> n;
//	deque<int> q;
//	int del = 0;//+ D ¶à 
//	//D---1
//	string str; cin >> str;
//	for (int i = 0; i < n; i++) {
//		if (str[i] == 'D') {
//			if (del < 0) {
//				del++;
//				continue;
//			}
//			if (del >= 0) {
//				del++;
//				q.push_back(1);
//			}
//		}
//		if (str[i] == 'R') {
//			if (del > 0) {
//				del--;
//				continue;
//			}
//			if (del <= 0) {
//				del--;
//				q.push_back(2);
//			}
//		}
//	}
//	int size = q.size();
//	while (true) {
//		int flag = 0;
//		deque<int> ano;
//		while(q.size()>0) {
//			if (q.front() == 1) {
//				if (del < 0) {
//					del++;
//				}
//				else 	if (del >= 0) {
//					del++;
//					ano.push_back(1);
//				}
//			}
//			if (q.front() == 2) {
//				if (del > 0) {
//					del--;
//
//				}
//				else if (del <= 0) {
//					del--;
//					ano.push_back(2);
//				}
//			}
//			q.pop_front();
//		}
//		if (ano.size() == size) {
//			if (del > 0) {
//				cout << 'D' << endl;
//			}
//			else {
//				cout << 'R' << endl;
//			}
//			return 0;
//		}
//		size = ano.size();
//		q = ano;
//	}
//	return 0;
//}