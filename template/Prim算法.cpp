const int MAXN = 5 + 1e3;
typedef int ElementType;

ElementType cost[MAXN][MAXN];//从0开始编号
ElementType lowc[MAXN];
struct Mst
{
	int a, b;
}tree[MAXN];//存储最小生成树
int from[MAXN];
bool visit[MAXN];

ElementType prim(int start, int n)
{
	memset(visit, 0, sizeof(visit));
	visit[start] = true;
	for (int i = 0; i < n; i++)
	{
		lowc[i] = cost[start][i];
		from[i] = start;
	}
	int pos;
	ElementType minc, re = 0;
	for (int i = 1; i < n; i++)
	{
		minc = INF;
		for (int j = 0; j < n; j++)
		{
			if (!visit[j] && minc > lowc[j])
			{
				minc = lowc[j];
				pos = j;
			}
		}
		if (minc == INF) return -1;//图不联通，返回-1
		re += minc;
		tree[i - 1].a = from[pos];
		tree[i - 1].b = pos;
		visit[pos] = true;
		for (int j = 0; j < n; j++)
		{
			if (!visit[j] && cost[pos][j] < lowc[j])
			{
				lowc[j] = cost[pos][j];
				from[j] = pos;
			}
		}
	}
	return re;
}

/******** how to use *************
int main()
{
	int n, m;
	while (scanf("%d", &n), n)
	{
		memset(cost, 0x3f, sizeof(cost));//初始化，再建图
		int a, b, c, d;
		m = n*(n - 1) / 2;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);
			if (d == 0) cost[a - 1][b - 1] = cost[b - 1][a - 1] = c;
			else cost[a - 1][b - 1] = cost[b - 1][a - 1] = 0;//建图
		}
		printf("%d\n", prim(0, n));
	}
	return 0;
}
********************************/