
const int MAXN = 5 + 1e3;//点数
const int MAXE = 5 + 1e5;//边数

typedef int ElementType;//可以修改int --->  double

struct Edge {
	int to, next;
	ElementType w;
	Edge() {
	};
	Edge(int to, ElementType w, int next) : to(to), w(w), next(next) {
	};
} edge[MAXE];
int head[MAXN], no;//head 边储存位置,no 边数计数
//初始化
void init(){
	memset(head, -1, sizeof(head));
	no = 0;
}
//加边
void add(int from, int to, ElementType w){
	edge[no] = Edge(to, w, head[from]);
	head[from] = no++;
}

ElementType dist[MAXN];
int pre[MAXN]; //用于输出路径
typedef pair<ElementType, int> PEI;
void dijkstra(int start){
	for (int i = 0; i<MAXN; i++) dist[i] = INF;
	dist[start] = 0;
	priority_queue<PEI, vector<PEI>, greater<PEI> > pq;
	pq.push(PEI(0, start));
	while (!pq.empty()) {
		PEI tmp = pq.top();
		pq.pop();
		int u = tmp.second;
		if (dist[u] < tmp.first) continue;
		for (int i = head[u]; i != -1; i = edge[i].next) {
			Edge &e = edge[i];
			if (dist[u] + e.w < dist[e.to]) {
				dist[e.to] = dist[u] + e.w;
				pre[e.to] = u;//用于输出路径
				pq.push(PEI(dist[e.to], e.to));
			}
		}
	}
}
bool visit[MAXN];//标记数组,用于spfa的队列
void spfa(int start){
	for (int i = 0; i<MAXN; i++) dist[i] = INF;
	memset(visit, 0, sizeof(visit));
	dist[start] = 0;//源点距离为0
	queue<int> q;
	q.push(start);//将源点加入队列
	visit[start] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();//取出队列头元素
		visit[u] = false;
		for (int i = head[u]; i != -1; i = edge[i].next) {
			//图以邻接表储存,遍历u的所有可达点
			Edge &e = edge[i];//辛成鑫学习徐恒达偷懒,起了个别名。
			if (dist[e.to]>dist[u] + e.w) {//如果松弛
				dist[e.to] = dist[u] + e.w;
				pre[e.to] = u;//用于输出路径
				if (!visit[e.to]) {//如果松弛，且不在队列中则加入队列
					q.push(e.to);
					visit[e.to] = true;
				}
			}
		}
	}
}
//打印路径
void path(int from, int to){
	stack<int> s;
	while (from != to) {
		s.push(to);
		to = pre[to];
	}
	printf("%d", from);
	while (!s.empty()) {
		printf(" %d", s.top()); s.pop();
	}
}

/* ********* how to use *************
   int main()
   {
    //1.建图：输入节点数n，边数m
    int n, m;
    scanf("%d%d", &n, &m);

    init(); ////初始化图
    while (m--)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
    }

    //2.调用
    dijkstra(1);
    spfa(1);
    //3.查询路径
    int v;
    scanf("%d", &v);
    path(1, v);
    printf("\n");

    return 0;
   }
 ************************************** */
