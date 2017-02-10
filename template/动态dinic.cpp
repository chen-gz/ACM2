const int maxn = 0;
const int maxm = 0;
const int INF = 0x3f3f3f3f;

struct maxflow
{
	long long ans;
	int cnt, head[maxn], q[maxn], h[maxn], s, e;
	struct data { int to, next, v; }p[maxm];
	void add(int u, int v, int w)
	{
		p[cnt].to = v; p[cnt].v = w; p[cnt].next = head[u]; head[u] = cnt++;
		p[cnt].to = u; p[cnt].v = 0; p[cnt].next = head[v]; head[v] = cnt++;
	}
	void init(int ss, int ee)
	{
		s = ss; e = ee;
		memset(head, -1, sizeof(head)); cnt = 0; ans = 0;
	}
	bool bfs()
	{
		int t = 0, w = 1, i, now;
		memset(h, -1, sizeof(h));
		h[s] = 0; q[0] = s;
		while (t < w)
		{
			now = q[t]; t++;
			i = head[now];
			while (~i)
			{
				if (h[p[i].to] == -1 && p[i].v)
				{
					h[p[i].to] = h[now] + 1; q[w++] = p[i].to;
				}
				i = p[i].next;
			}
		}
		if (h[e] == -1)return 0;
		return 1;
	}
	int dfs(int x, int f)
	{
		if (x == e)return f;
		int i = head[x];
		int w, use = 0;
		while (~i)
		{
			if (p[i].v && h[p[i].to] == h[x] + 1)
			{
				w = f - use;
				w = dfs(p[i].to, min(w, p[i].v));
				p[i].v -= w;
				p[i ^ 1].v += w;
				use += w;
				if (use == f)return f;
			}
			i = p[i].next;
		}
		if (!use)h[x] = -1;
		return use;
	}
	void dinic() { while (bfs())ans += dfs(s, INF); }
};