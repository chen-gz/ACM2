// ±º‰∏¥‘”∂»O(mlog(n))
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int len[2000002],to[2000002],next[2000002],head[1000002],a[1000002],b[1000002],c[1000002];
int now,tot,cases,n,m;
__int64 dis[1000002],res;
int heap[1000002],size;
short vis[1000002];
void add(int a,int b,int c)
{
	tot++;len[tot]=c;to[tot]=b;
	next[tot]=head[a];head[a]=tot;
}
void down(int p)
{
	int temp=p;
	if((p*2<=size)&&(dis[heap[p*2]]<dis[heap[temp]]))temp=p*2;
	if((p*2+1<=size)&&(dis[heap[p*2+1]]<dis[heap[temp]]))temp=p*2+1;
	if(temp!=p){swap(heap[p],heap[temp]);down(temp);}
}
void up(int p)
{
	if(dis[heap[p/2]]>dis[heap[p]]){swap(heap[p],heap[p/2]);up(p/2);}
}
void dijkstra(int p)
{
	for(int i=1;i<=n;i++)dis[i]=0x7fffffff;memset(vis,0,sizeof(vis));size=0;
	size++;heap[size]=p;vis[p]=1;dis[p]=0;
	while(size)
	{
		now=heap[1];heap[1]=heap[size];size--;down(1);vis[now]=2;
		for(int i=head[now];i;i=next[i])
		{
			//printf("%d ",len[i]);
			if(vis[to[i]]==2)continue;
			if(vis[i]==1){if(dis[to[i]]>dis[now]+len[i])dis[to[i]]=dis[now]+len[i];}
			else
			{
				vis[to[i]]=1;
				size++;heap[size]=to[i];
				dis[to[i]]=min(dis[to[i]],dis[now]+len[i]);
				up(size);
			}
		}
		//puts("");for(int i=1;i<=size;i++)printf("%d ",heap[i]);puts("");
		//for(int i=1;i<=n;i++)printf("%I64d ",dis[i]);puts("");
	}
}
int main()
{
scanf("%d",&cases);
while(cases--)
{
	scanf("%d %d",&n,&m);memset(head,0,sizeof(head));tot=0;
	for(int i=1;i<=m;i++){scanf("%d %d %d",&a[i],&b[i],&c[i]);add(a[i],b[i],c[i]);}
	res=0;
	dijkstra(1);
	//for(int i=1;i<=n;i++)printf("%I64d ",dis[i]);puts("");
	for(int i=1;i<=n;i++)res+=dis[i];
	//printf("%I64d\n",res);
	memset(head,0,sizeof(head));tot=0;
	for(int i=1;i<=m;i++)add(b[i],a[i],c[i]);
	dijkstra(1);
	//for(int i=1;i<=n;i++)printf("%I64d ",dis[i]);puts("");
	for(int i=1;i<=n;i++)res+=dis[i];
	printf("%I64d\n",res);
}
return 0;
}
