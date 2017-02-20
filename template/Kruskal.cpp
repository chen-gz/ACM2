const int MAXN = 5 + 1e2;
const int MAXE = 5 + 1e4;

//并查集开始
int tree[MAXN], deep[MAXN];

void init()//初始化一个含有n个元素的并查集，复杂度n
{
	int i;
	for (i = 0; i < MAXN; i++)
	{
		tree[i] = i;
	}
	memset(deep, 0, sizeof(deep));
}

int find(int n)//查找n的根节点并压缩路径，复杂度1
{
	if (tree[n] == n)
	{
		return n;
	}
	return tree[n] = find(tree[n]);
}

void unit(int m, int n)//把两个独立的集合联系起来，复杂度1
{
	int root_m, root_n;
	root_m = find(m);
	root_n = find(n);
	if (root_m == root_n)
	{
		return;
	}
	if (deep[m] > deep[n])
	{
		tree[root_n] = root_m;
	}
	else
	{
		tree[root_m] = root_n;
		if (deep[m] == deep[n])
		{
			deep[root_n]++;
		}
	}
}
//并查集结束

typedef int ElementType;

struct Edge
{
	int u,v;
	ElementType w;
	Edge() {};
	Edge(int u, int v, ElementType w) : u(u),  v(v), w(w) {};
} edge[MAXE];
int mst[MAXN];//记录最小生成树中的边
int no;//no = 0;来进行初始化

void add(int from, int to, ElementType w)
{
	edge[no++] = Edge(from, to, w);
}

bool cmp(struct Edge a, struct Edge b)
{
	return a.w < b.w;
}

ElementType kruskal(int n)//0还是1开始编号无所谓
{
	init();
	sort(edge, edge + no, cmp);
	int cnt = 0;
	ElementType re = 0;
	for (int i = 0; i < no; i++)
	{
		if (find(edge[i].u) != find(edge[i].v))
		{
			unit(edge[i].u, edge[i].v);
			mst[cnt++] = i;
			re += edge[i].w;
			if (cnt == n - 1) break;
		}
	}
	if (cnt != n - 1) re = -1;
	return re;
}

/************* huw to use ************
int main()
{
	int n, m;
	while (scanf("%d",&n), n)
	{
		int a, b, c, d;
		m = n*(n - 1) / 2;
		no = 0;//初始化
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d %d", &a, &b, &c,&d);
			if (d == 0) add(a, b, c);
			else add(a, b, 0);
		}
		printf("%d\n", kruskal(n));
	}
	return 0;
}
***************************************/