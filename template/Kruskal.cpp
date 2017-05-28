const int MAXN = 5 + 1e2;
const int MAXE = 5 + 1e4;

//���鼯��ʼ
int tree[MAXN], deep[MAXN];

void init()//��ʼ��һ������n��Ԫ�صĲ��鼯�����Ӷ�n
{
	int i;
	for (i = 0; i < MAXN; i++)
	{
		tree[i] = i;
	}
	memset(deep, 0, sizeof(deep));
}

int find(int n)//����n�ĸ��ڵ㲢ѹ��·�������Ӷ�1
{
	if (tree[n] == n)
	{
		return n;
	}
	return tree[n] = find(tree[n]);
}

void unit(int m, int n)//�����������ļ�����ϵ���������Ӷ�1
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
//���鼯����

typedef int ElementType;

struct Edge
{
	int u,v;
	ElementType w;
	Edge() {};
	Edge(int u, int v, ElementType w) : u(u),  v(v), w(w) {};
} edge[MAXE];
int mst[MAXN];//��¼��С�������еı�
int no;//no = 0;�����г�ʼ��

void add(int from, int to, ElementType w)
{
	edge[no++] = Edge(from, to, w);
}

bool cmp(struct Edge a, struct Edge b)
{
	return a.w < b.w;
}

ElementType kruskal(int n)//0����1��ʼ�������ν
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
		no = 0;//��ʼ��
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