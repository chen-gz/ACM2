//#include<iostream>
//#include<algorithm>
//#include<queue>
//#include<set>
//using namespace std;
//set<int> a[100001];
//int main() {
//	int n, m;
//	while (cin >> n >> m && n != -1 && m != -1) {
//		for (int i = 0; i < 100001; i++) {
//			a[i].clear();
//		}
//		bool Y = true;
//		if (n == 0 && m == 0) {
//			cout << "Yes" << endl;
//			continue;
//		}
//			
//		do {
//			if (a[n].count(m) != 0  || a[m].count(n) !=0) {
//				Y = false;
//				cout << "No" << endl;
//			}
//			a[n].insert(m);
//			a[m].insert(n);
//		//	if (a[m].count(n)) a[m].erase(n);
//		} while (cin >> n >> m && n != 0 && m != 0);
//		//BFS
//		int beg = -1;
//		for (int i = 0; i < 100001; i++) {
//			if (a[i].size() != 0) {
//				beg = i;
//				break;
//			}
//		}
//		set<int> finded;
//		if (beg == -1) {
//			Y = false;
//			cout << "No" << endl;
//			continue;
//		}
//		finded.insert(beg);
//		queue<int> search;
//		search.push(beg);
//		while (!search.empty()) {
//			bool flag = false;
//			int tmp = search.front(); search.pop();
//			set<int>::iterator iter = a[tmp].begin();
//			for (; iter != a[tmp].end(); iter++) {
//				if (finded.count(*iter) != 0) {
//					flag = true;
//					cout << "No" << endl;
//					Y = false;
//					break;
//				}
//				finded.insert(*iter);
//				search.push(*iter);
//				if (a[*iter].count(tmp)) a[*iter].erase(tmp);
//			}
//			if (flag) {
//				Y = false;
//				break;
//			}
//			else
//				a[tmp].clear();
//		}
//		if (Y){
//			for (int i = 0; i < 100001; i++) {
//				if (a[i].size() != 0) {
//					Y = false; break;
//				}
//			}
//			if (Y)
//				cout << "Yes" << endl;
//			else {
//				cout << "No" << endl;
//			}
//		}
//	}
//}