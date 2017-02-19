#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
const int inf=300005;
struct node
{
	int to,cost;
	node(int to=0,int cost=0) : to(to),cost(cost){
	}
	bool operator < (const struct node p) const
	{
		return cost>p.cost;
	}
};
vector<node> g1[maxn];
vector<node> g2[maxn];
int dis0[maxn],disa[maxn],disb[maxn];
bool vis[maxn];
int i,j,k,l,m,n,a,b;
priority_queue<node> q;
void Dijkstra(int st,int *dis,vector<node> *g)
{
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis)); vis[st]=true;
	for(unsigned int i=0; i<g[st].size(); i++)
	{
		node v=g[st][i];
		dis[v.to]=v.cost;
		q.push(v);
	}
	for(int l=1; l<=n; l++)
	{
		if(q.empty()) break;
		int t=q.top().to;
		vis[t]=true;
		for(unsigned int i=0; i<g[t].size(); i++)
		{
			int v=g[t][i].to;
			if(dis[v]>dis[t]+g[t][i].cost)
			{
				dis[v]=dis[t]+g[t][i].cost;
				q.push(node(v,dis[v]));
			}
		}
		while(!q.empty() && vis[q.top().to]) q.pop();
	}
}
int main()
{
	cin>>n>>m>>a>>b;
	for(i=1; i<=m; i++)
	{
		scanf("%d%d",&j,&k);
		g1[j].push_back(node(k,1));
		g2[k].push_back(node(j,1));
	}
	for(i=0; i<=n; i++) dis0[i]=disa[i]=disb[i]=inf;
	dis0[0]=disa[a]=disb[b]=0;
	Dijkstra(0,dis0,g1);
	Dijkstra(a,disa,g2);
	Dijkstra(b,disb,g2);
	m=3*inf;
	for(i=0; i<=n; i++)
	{
		k=dis0[i]+disa[i]+disb[i];
		m=min(k,m);
	}
	printf("%d",m);
	return 0;
}
