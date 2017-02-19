////凭啥C++就会T
//cin,cout会T
//#include<cstdio>
//#include<cstdlib>
//#include<cstring>
//#include<cmath>
//#include<queue>
//#include<vector>
//#include<algorithm>
//using namespace std;
//const int INF = 100000000;
//
//const int maxn = 1e5 + 200;
//int dp_min[maxn][20], dp_max[maxn][20], mm[maxn];//dp[1……n][0]初始化，min/max
//int n, q;
//void init()
//{
//	mm[0] = -1;
//	for (int i = 1; i <= n; i++)
//	{
//		mm[i] = ((i&(i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
//
//	}
//
//	for (int j = 1; j <= mm[n]; j++)
//	{
//		for (int i = 1; i + (1 << j) - 1 <= n; i++)
//		{
//			dp_min[i][j] = min(dp_min[i][j - 1], dp_min[i + (1 << (j - 1))][j - 1]);
//			dp_max[i][j] = max(dp_max[i][j - 1], dp_max[i + (1 << (j - 1))][j - 1]);
//		}
//	}
//}
//
//int rmq_difference(int x, int y)
//{
//	int k = mm[y - x + 1];
//	return  max(dp_max[x][k], dp_max[y - (1 << k) + 1][k]) - min(dp_min[x][k], dp_min[y - (1 << k) + 1][k]);
//}
//
//
//
//int main()
//{
//	int x, y, t;
//	scanf("%d%d", &n, &q);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &t);
//		dp_min[i][0] = dp_max[i][0] = t;
//	}
//	init();
//	for (int i = 1; i <= q; i++)
//	{
//		scanf("%d%d", &x, &y);
//		printf("%d\n", rmq_difference(x, y));
//		//test;
//	}
//
//	return 0;
//}
