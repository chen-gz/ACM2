//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<iostream>
//#include<string>
//#include<functional>
//#include<queue>
//using namespace std;
//const int N = 300000;
//typedef struct node {
//	int l, r;
//	int index;
//}NODE;
//NODE aa[300001];
//typedef struct hhh {
//	int l, r, len, index;
//}ANS;
//bool cmp(NODE a, NODE b) {
//	if (a.l == b.l) {
//		return a.r < b.r;
//	}
//	return a.l < b.l;
//}
//bool cmp2(NODE a, NODE b) {
//	if (a.r == b.r) {
//		return a.r < b.r;
//	}
//	return a.r > b.r;
//}
//int b[300001];
//int main() {
//	priority_queue<int,vector<int>,greater<int>> q;
//	int n, k; cin >> n >> k;
//	for (int i = 0; i < n; i++) {
//		scanf("%d %d", &aa[i].l, &aa[i].r);
//		aa[i].index = i;
//	}
//	sort(aa, aa + n, cmp);
//	bool have = false;
//	ANS ans;
//	ans.l = ans.r = ans.len = 0;
//	for (int i = 0; i < n; i++) {
//		q.push(aa[i].r);
//		while (!q.empty() && (q.top() < aa[i].l)){
//			q.pop();
//	}
//		while (q.size() > k) {
//			q.pop();
//		}
//		if (q.size() == k) {
//			int len = q.top() - aa[i].l;
//			if (ans.len < len) {
//				ans.len = len;
//				ans.l = aa[i].l;
//				ans.r = aa[i].r;
//				ans.index = i;
//				have = true;
//			}
//		}
//	}
//	if (have) {
//		cout << ans.len+1 << endl;
//		sort(aa, aa + ans.index+1, cmp2);
//		for (int i = 0; i < k; i++) {
//			b[i]= aa[i].index+1;
//		}
//		sort(b, b + k);
//		for (int i = 0; i < k; i++) {
//			printf("%d ",b[i]);
//		}
//	}
//	else {
//		printf("0\n");
//		for (int i = 0; i < k; i++) {
//			printf("%d ", i + 1);
//		}
//	}
//	cout << endl;
//}