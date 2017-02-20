//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<iostream>
//#define N 100003
//using namespace std;
//
//char str[N];
//int gogogo[N], gg[N], fuck[N];
//
//int main(){
//	int n, Orz = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> gogogo[i];
//		if (gogogo[i] != 0)
//			Orz++;
//	}
//	if (Orz == 0)
//	{
//		cout<<"NO\n";
//		return 0;
//	}
//
//	cout<<"YES\n";
//	int l = 0, r = 0, ans = 0, p = 0;
//	while (r < n){
//		if (gogogo[r] == 0)
//			r++;
//		else{
//			while (gogogo[r + 1] == 0 && r + 1 < n)
//				r++;
//			gg[p] = l + 1;
//			fuck[p] = r + 1;
//			p++;
//			r++;
//			l = r;
//		}
//	}
//	cout << p << endl;
//	for (int i = 0; i < p; i++){
//		printf("%d %d\n", gg[i], fuck[i]);
//	}
//	return 0;
//}
