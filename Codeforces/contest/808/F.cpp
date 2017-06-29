#include <bits/stdc++.h>
using namespace std;
#define maxn 1055555
//素数保存在prime数组
int mark[maxn], prime[maxn], res;
set<int> primes;
void get_prime(int n) {
	//从2----n的素数
	memset(mark, 0, sizeof(mark));
	res = 0;
	for (int i = 2; i <= n; i++) {
		if (!mark[i])
			mark[i] = prime[res++] = i;
		for (int j = 0; j < res && prime[j] * i <= n; j++) {
			mark[i * prime[j]] = prime[j];
			if (i % prime[j] == 0)
				break;
		}
	}
	for (int i = 0; i < res; i++) {
		primes.insert(prime[i]);
	}
}

/*
需要的头文件:cstring,queue;
需要命名空间：std,Dinic;
可自定义POINT_NUM;默认201;点数
可自定义EDGE_NUM;默认2001;边数
如果在必要情况下，可以将region edge取出；放到class dinic外
*/
// by Wendell
namespace Dinic
{
#ifndef INT_MAX
#define INT_MAX 2147483647
#endif
#ifndef POINT_NUM
#define POINT_NUM 25000
#endif
#ifndef EDGE_NUM
#define EDGE_NUM 25000
#endif
class dinic {
private:
	int head[POINT_NUM];
	int edgenum;
	struct node {
		int from;//起点
		int to;//终点
		int next;
		int weight;//权值
	} edge[EDGE_NUM];
	void build_edge(int _edgenum, int _from, int _to, int _w) {
		bool has_e = false;
		if (_from == _to)
			return ;
		for (int i = head[_from]; i != -1; i = edge[i].next) {
			//判重边
			if (edge[i].to == _to) {
				has_e = true;
				edge[i].weight += _w;
				break;
			}
		}
		if (!has_e)
		{
			edge[edgenum].from = _from;
			edge[edgenum].to = _to;
			edge[edgenum].weight += _w;
			edge[edgenum].next = head[_from];
			head[_from] = edgenum++;
		}
	};
public :
	int lev[POINT_NUM];//点位于的层次
	int start_point;//起点
	int end_point;//终点
	void init() {
		//初始化
		memset(head, -1, sizeof(head));
		for (int i = 0; i < POINT_NUM; i++) {
			edge[i].weight = 0;
		}
	}
	bool bfs() {
		//bfs优化，标记点的层次
		queue<int>q;
		memset(lev, -1, sizeof(lev));
		lev[start_point] = 0;
		q.push(start_point);
		while (!q.empty()) {
			int now = q.front(); q.pop();
			int next;
			for (int i = head[now]; i != -1; i = edge[i].next) {
				//遍历每一条边
				if (edge[i].weight > 0 && lev[next = edge[i].to] < 0) {
					lev[next] = lev[now] + 1;
					if (next == end_point)
						return true;
					q.push(next);
				}
			}
		}
		return false;
		//return lev[end_point] != -1;
	}
	int dfs(int u, int minc) {
		//dfs求剩余网络最小流量
		if (u == end_point)
			return minc;
		int f;
		for (int p = head[u]; p != -1; p = edge[p].next) {
			//遍历每一条边
			int next = edge[p].to;
			if (  edge[p].weight > 0 && lev[edge[p].from] + 1 == lev[next]) {
				int f = dfs(next, min(minc, edge[p].weight));
				if (f > 0) {
					edge[p].weight -= f;
					edge[p ^ 1].weight += f;
					return f;
					//p为偶自然数，p^1=p+1;(p+1)^1=p;
					//正向边存为偶数；
				}
			}
		}
		return 0;
	}
public:
	int MaxFlow;
	dinic() {
		edgenum = 0;
		init();
		MaxFlow = 0;
	}
	void addedge(int _from, int _to, int _weight) {
		//双向图，正向权值为_weight;反向权值为0；
		build_edge(edgenum, _from, _to, _weight);
		build_edge(edgenum, _to, _from, 0);
	}
	int Work(int _start_point, int _end_point) {
		start_point = _start_point;
		end_point = _end_point;
		int cur_flow;
		while (bfs()) {
			while (cur_flow = dfs(start_point, INT_MAX))
				MaxFlow += cur_flow;
		}
		return MaxFlow;
	}
//调用Work函数实现，放回最大流量值；参数为起始点和终止点；
};
}
struct  node
{
	int power;
	int magic;
	int level;
} ac[105];
int inf = 0xffff;
bool cmp(node a , node b ) {
	return a.level < b.level;
}
int endpoint = 102;
int target;	int n;
using namespace Dinic;
bool judge(int x) {
	dinic d;
	int 	fuck  = 0 ;
	int pos = 0;
	bool have = false ;
	int value = 0 ;
	for (int i = 0; i < n; i++) {
		if (ac[i].level < x ) {
			if (ac[i].magic == 1) {
				pos = i;
				have = true;
				value = max(value, ac[i].power);
				continue;
			}
			fuck += ac[i].power;
			if (ac[i].magic % 2 == 0) {
				d.addedge(i + 1, 102, ac[i].power);
			}
			else {
				d.addedge(0, i + 1, ac[i].power);
				for (int k = 0 ; k < n; k++) {
					if (primes.count(ac[i].magic + ac[k].magic ) && ac[k].magic != 1) {
						d.addedge(i + 1, k + 1, inf);
					}
				}
			}

		}
		else {

			break;
		}
	}
	if (have) {
		fuck += value;
		d.addedge(0, pos + 1, value);
		for (int k = 0 ; k < n; k++) {
			if (primes.count(1 + ac[k].magic) && ac[k].magic != 1) {
				d.addedge(pos + 1, k + 1, inf);
			}
		}
	}
	// cout << "Orz";
	// cout << x;
	// cout << d.Work(0,  102) << "Orz";
	// cout << "      " << fuck << "  " << target << endl;
	return fuck - d.Work(0, 102) >= target  ;

}
int maxlevel = 0;
int main(int argc, char const *argv[]) {
	// FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	//       *fo = freopen("/home/wendell/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	get_prime(1000000);
	cin >> n >> target;
	for (int i = 0; i < n; ++i) {
		cin >> ac[i].power >> ac[i].magic >> ac[i].level;
		maxlevel = max(maxlevel, ac[i].level);
	}
	// cout << "hhh" << endl;
	sort(ac, ac + n, cmp);
	// cout << "hh" << endl;
	int l = 0, r = maxlevel + 1;
	while (l < r) {
		int mid = (l + r) / 2;
		// cout << l << " " << r << endl;
		if (judge(mid)) {
			r = mid;
		}
		else l = mid + 1;

	}
	// cout << "hhhh" << endl;
	// cout << l << endl;
	if (judge(l))
		cout << l - 1 << endl;
	else
		cout << -1 << endl;
	return 0;
}