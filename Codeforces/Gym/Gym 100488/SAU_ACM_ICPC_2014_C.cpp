//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<functional>
//#include<cmath>
//#include<cstdio>
//#define LL long long
//using namespace std;
//const int maxa = 50000 + 5;
//vector<LL> prime, ans;
//LL vis[maxa], k;
//void WTF()
//{
//	LL m = sqrt(maxa), K = k;
//	for (LL i = 2; i <= m; i++) if (!vis[i])
//		for (LL j = i*i; j < maxa; j += i)
//			vis[j] = 1;
//	for (LL i = 2; i < maxa; i++)
//		if (!vis[i])
//			prime.push_back(i);
//	ans.push_back(1);
//	for (int i = 0; i < prime.size(); i++) {
//		LL tmp = 1, size = ans.size(), cnt = 0;
//		while (K%prime[i] == 0) {
//			cnt++;
//			K /= prime[i];
//		}
//		cnt *= 2;
//		while (cnt--) {
//			tmp *= prime[i];
//			for (int j = 0; j < size; j++)
//				ans.push_back(tmp*ans[j]);
//		}
//		if (K == 1) break;
//		if (i == prime.size() - 1 && K != 1)
//			prime.push_back(K);
//	}
//	sort(ans.begin(), ans.end());
//	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
//	printf("%d\n", ans.size());
//	for (int i = 0; i < ans.size(); i++) {
//		printf("%I64d %I64d\n", ans[i] + k, k*k / ans[i] + k);
//	}
//}
//int main()
//{
//	scanf("%I64d", &k);
//	WTF();
//}