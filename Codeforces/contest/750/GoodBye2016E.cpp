//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<set>
//#include<queue>
//#include<string>
//#include<cstring>
//#include<cstdio>
//using namespace std;
//typedef struct node {
//	int a;//2
//	int b;//0
//	int c;//1
//	int d;//7
//	vector<int> gg;
//}NODE;
//vector< NODE > GG;
//int cnt = 0;
//int main() {
//	int n; int q;
//	cin >> n >> q;
//	string a;
//	cin >> a;
//	queue<int> pos2;
//	queue<int> pos0;
//	queue<int> pos1;
//	queue<int> pos6;
//	queue<int> pos7;
//	for (int i = 0; i < n; i++) {
//		if (a[i] == '2')
//			pos2.push(i);
//		else if (a[i] == '0')
//			pos0.push(i);
//		else if (a[i] == '1')
//			pos1.push;
//		else if (a[i] == '6')
//			pos6.push(i);
//		else if (a[i] == '7')
//			pos7.push(i);
//	}
//	int flag = true;
//	while (!pos2.empty()) {
//		if (flag == false)
//			break;
//		NODE tmp;
//		int c = pos2.front(); pos2.pop();
//		if (pos0.empty()) {
//			flag = false;
//			break;
//		}
//		while (c > pos0.front()) {
//			if (pos0.empty()) {
//				flag = false;
//				break;
//			}
//			pos0.pop();
//		}
//			
//		int cc = pos0.front;
//		while (cc > pos1.front()) {
//			if (pos1.empty()) {
//				flag = false;
//				break;
//			}
//			pos1.pop();
//		}
//			
//		int ccc = pos1.front();
//		while (ccc > pos7.front()) {
//			if (pos7.empty()) {
//				flag = false;
//				break;
//			}
//			pos7.pop();
//		}
//			
//		int cccc = pos7.front();
//
//		while (cccc > pos1.front()) {
//			if (pos1.empty()) {
//				break;
//			}
//			ccc = pos1.front();
//			pos1.pop();
//		}
//		//while (ccc > pos0.front()) {
//		//	if (pos0.empty()) {
//		//		break;
//		//	}
//		//	cc = pos0.front();
//		//	pos0.pop();
//		//}
//		//while (ccc > pos2.front()) {
//		//	if (pos2.empty()) {
//		//		break;
//		//	}
//		//	cc = pos2.front();
//		//	pos2.pop();
//		//}
//		tmp.a = c; tmp.b = cc; tmp.c = ccc; tmp.d = cccc;
//		GG.push_back(tmp);
//	}
//	for (int i = 0; i < q; i++) {
//		int b, e; cin >> b >> e;
//		while()
//	}
//	
//}