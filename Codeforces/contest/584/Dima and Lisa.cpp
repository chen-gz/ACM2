//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<string>
//#include<algorithm>
//#include<queue>
//#include<cmath>
//#include<map>
//#include<bitset>
//#include<set>
//#include<vector>
//using namespace std;
//typedef long long ll;
//#define mem(a) memset(a,0,sizeof(a))
//#define meminf(a) memset(a,127,sizeof(a));
//#define TS printf("111111\n");
//#define FOR(i,a,b) for( int i=a;i<=b;i++)
//#define FORJ(i,a,b) for(int i=a;i>=b;i--)
//#define READ(a,b,c) scanf("%d%d%d",&a,&b,&c)
//#define inf 100000
//const int S = 20;
//long long mult_mod(long long a, long long b, long long c)
//{
//	a %= c;
//	b %= c;
//	long long ret = 0;
//	while (b)
//	{
//		if (b & 1) { ret += a; ret %= c; }
//		a <<= 1;
//		if (a >= c)a %= c;
//		b >>= 1;
//	}
//	return ret;
//}
//long long pow_mod(long long x, long long n, long long mod){
//	if (n == 1)return x%mod;
//	x %= mod;
//	long long tmp = x;
//	long long ret = 1;
//	while (n){
//		if (n & 1) ret = mult_mod(ret, tmp, mod);
//		tmp = mult_mod(tmp, tmp, mod);
//		n >>= 1;
//	}
//	return ret;
//}
//bool check(long long a, long long n, long long x, long long t){
//	long long ret = pow_mod(a, x, n);
//	long long last = ret;
//	for (int i = 1; i <= t; i++){
//		ret = mult_mod(ret, ret, n);
//		if (ret == 1 && last != 1 && last != n - 1) return true;
//		last = ret;
//	}
//	if (ret != 1) return true;
//	return false;
//}
//bool Miller_Rabin(long long n){
//	if (n<2)return false;
//	if (n == 2)return true;
//	if ((n & 1) == 0) return false;
//	long long x = n - 1;
//	long long t = 0;
//	while ((x & 1) == 0) { x >>= 1; t++; }
//	for (int i = 0; i<S; i++){
//		long long a = rand() % (n - 1) + 1;
//		if (check(a, n, x, t))
//			return false;
//	}
//	return true;
//}
//#define maxn 5500
//int p[maxn], H[maxn];
//vector<int >G;
//void init(){
//	mem(H);
//	H[1] = 1;
//	for (int i = 2; i<maxn; i++){
//		if (!H[i])
//			for (int j = i + i; j<maxn; j += i)
//				H[j] = 1;
//	}
//	for (int i = 1; i<maxn; i++){
//		if (!H[i])
//			G.push_back(i);
//	}
//}
//int main()
//{
//	init();
//	int n;
//	cin >> n;
//	if (n <= 5500){
//		for (int i = 0; i<G.size(); i++)if (G[i] == n) {
//			cout << 1 << endl;
//			cout << G[i] << endl; return 0;
//		}
//		for (int i = 0; i<G.size(); i++)
//			for (int j = 0; j<G.size(); j++)
//				if (i != j&&G[i] + G[j] == n){
//					cout << 2 << endl;
//					cout << G[i] << " " << G[j] << endl;
//					return 0;
//				}
//		for (int i = 0; i<G.size(); i++)
//			for (int j = 0; j<G.size(); j++)
//				for (int k = 0; k<G.size(); k++)
//					if (i != j&&i != k&&j != k&&G[i] + G[j] + G[k] == n){
//						cout << 3 << endl;
//						cout << G[i] << " " << G[j] << " " << G[k] << endl; return 0;
//					}
//	}
//	else {
//		n = n - 3;
//		for (int i = n - 1; i >= 1; i--){
//			int x = n - i;
//			int y = i;
//			if (Miller_Rabin(x) && Miller_Rabin(y)){
//				cout << 3 << endl;
//				cout << 3 << " " << x << " " << y << endl; return 0;
//			}
//		}
//	}
//	return 0;
//}