//单源最短路径dijkstra算法，使用优先队列优化
#include <iostream>
#include <cstdio>
#include <functional>
#include <queue>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
const int MAX_V = 600001;//最大边的个数
#define INT_MAX 2147483647
struct edge
{
	int to;
	double cost;
	edge(int to, double cost) {
		this->to = to;
		this->cost = cost;
	}
};
typedef pair<double, int> P;
//int V;//点的实际个数
// 计数开始为0 所以若点 从1开始计算，则V需要+1；
double d[MAX_V];//最短距离
vector<edge> G[MAX_V]; //的格式；
bool used[MAX_V];
void dijkstra(int start, vector<edge> G[], int V, double d[]) {
	//参数说明
	//start 起点 ,G[] 图， V 点的数量 ,d[] 为返回的结果

	priority_queue<P, vector<P>, greater<P> > que;
	memset(used, false, sizeof(used));
	fill(d, d + V, INT_MAX);
	d[start] = 0;
	que.push(P(0, start));
	while (!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first || used[v])
			continue;
		used[v] = true;
		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}
double distance (pair<double,double> a, pair<double,double> b) {
	double x = b.first - a.first;
	double y = b.second - a.second;
	return sqrt(x*x + y*y);
};
pair<double, double> coor[1505];
int main(int argc, char const *argv[]) {
	//freopen("input.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) && n) {
		double cost[1505];
		for (int i = 1; i <= n; i++) {
			scanf("%lf %lf", &coor[i].first, &coor[i].second);
			scanf("%lf", &cost[i]);
		}
		coor[n+1].first = 100; coor[n+1].second = 100;
		coor[0].first = 0; coor[0].second = 0;
		cost[0] = 0; cost[n + 1] = 1;
		cost[n + 2] = 0;
		for (int i = 0; i <10000; i++) {
			G[i].clear();
		}
		for (int i = 0; i < n+2; i++) {
			double cost_sum = 1;
			for (int j = i + 1; j < n+2; j++) {
				G[i].push_back(edge(j,  cost_sum + distance(coor[i], coor[j])));
				cost_sum += cost[j];
			}
		}
		dijkstra(0, G, n + 2, d);
		printf("%.3f\n", d[n+1]);
	}
	return 0;
}
