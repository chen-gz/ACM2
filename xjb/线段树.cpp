//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int maxn = 1e5 + 200;
//int dp_min[maxn][20], dp_max[maxn][20], mm[maxn];//dp[1°≠°≠n][0]≥ı ºªØ£¨min/max
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