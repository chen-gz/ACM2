//H
//POJ 2135
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn = 1005;
const int inf = 0x3f3f3f3f;
struct Edge
{
	int from,to,next,flow,cost;
}edge[maxn*maxn];
int n,m,cnt,head[maxn],pre[maxn];
int dis[maxn],st,ed;
bool inq[maxn];

void addedge(int u,int v,int flow,int cost)
{
	edge[cnt].from = u;
	edge[cnt].to = v;
	edge[cnt].flow = flow;
	edge[cnt].cost = cost;
	edge[cnt].next = head[u];
	head[u] = cnt++;
	swap(u,v);
	edge[cnt].from = u;
	edge[cnt].to = v;
	edge[cnt].flow = 0;
	edge[cnt].cost = -cost;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

int spfa(int s,int t)
{
	queue<int> q;
	memset(dis,inf,sizeof(dis));
	memset(inq,false,sizeof(inq));
	memset(pre,-1,sizeof(pre)); //pre[i]表示最短路径上以i为终点的边的编号
	dis[s] = 0;
	inq[s] = true;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = false;
		for(int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to;
			if(dis[v] > dis[u] + edge[i].cost && edge[i].flow > 0)
			{
				dis[v] = dis[u] + edge[i].cost;
				pre[v] = i;
				if(inq[v] == false)
				{
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
	return dis[t] != inf;
}

int MCMF(int s,int t)
{
	int mincost = 0,minflow,sumflow = 0; //最小费用，路径中最小流量，总流量
	while(spfa(s,t)) //找当前的最短路
	{
		minflow = inf;
		for(int i = pre[t]; i != -1; i = pre[edge[i].from])
			minflow = min(minflow,edge[i].flow);
		sumflow += minflow;
		for(int i = pre[t]; i != -1; i = pre[edge[i].from])
		{
			edge[i].flow -= minflow;
			edge[i^1].flow += minflow;
		}
		mincost += dis[t] * minflow;
	}
	return mincost;
}

int main()
{
	int u,v,c;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		cnt = 0;
		memset(head,-1,sizeof(head));
		for(int i = 1; i <= m; i++)
		{
			scanf("%d%d%d",&u,&v,&c);
			addedge(u,v,1,c);
			addedge(v,u,1,c);
		}
		st = 0, ed = n + 1;
		addedge(st,1,2,0); //有来回，所以容量为2
		addedge(n,ed,2,0);
		printf("%d\n",MCMF(st,ed));
	}
	return 0;
}