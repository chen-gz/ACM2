/*
POJ 3281 最大流
//源点-->food-->牛(左)-->牛(右)-->drink-->汇点
//精髓就在这里，牛拆点，确保一头牛就选一套food和drink的搭配

*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

//****************************************************
//最大流模板
//初始化：g[][],start,end
//******************************************************
const int MAXN=500;
const int INF=0x3fffffff;
int g[MAXN][MAXN];//存边的容量，没有边的初始化为0
int path[MAXN],flow[MAXN],start,end;
int n;//点的个数，编号0-n.n包括了源点和汇点。

queue<int>q;
int bfs()
{
    int i,t;
    while(!q.empty())q.pop();//把清空队列
    memset(path,-1,sizeof(path));//每次搜索前都把路径初始化成-1
    path[start]=0;
    flow[start]=INF;//源点可以有无穷的流流进
    q.push(start);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t==end)break;
        //枚举所有的点，如果点的编号起始点有变化可以改这里
        for(i=0;i<=n;i++)
        {
            if(i!=start&&path[i]==-1&&g[t][i])
            {
                flow[i]=flow[t]<g[t][i]?flow[t]:g[t][i];
                q.push(i);
                path[i]=t;
            }
        }
    }
    if(path[end]==-1)
		return -1;//即找不到汇点上去了。找不到增广路径了
    return flow[end];
}
int Edmonds_Karp()
{
    int max_flow=0;
    int step,now,pre;
    while((step=bfs())!=-1)
    {
        max_flow+=step;
        now=end;
        while(now!=start)
        {
            pre=path[now];
            g[pre][now]-=step;
            g[now][pre]+=step;
            now=pre;
        }
    }
    return max_flow;
}


int main()
{
    int N,F,D;
    while(scanf("%d%d%d",&N,&F,&D)!=EOF)
    {
        memset(g,0,sizeof(g));
        n=F+D+2*N+1;
        start=0;
        end=n;
        for(int i=1;i<=F;i++)
			g[0][i]=1;
        for(int i=F+2*N+1;i<=F+2*N+D;i++)
			g[i][n]=1;
        for(int i=1;i<=N;i++)
			g[F+2*i-1][F+2*i]=1;
        int k1,k2;
        int u;
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d",&k1,&k2);
            while(k1--)
            {
                scanf("%d",&u);
                g[u][F+2*i-1]=1;
            }
            while(k2--)
            {
                scanf("%d",&u);
                g[F+2*i][F+2*N+u]=1;
            }
        }
        printf("%d\n",Edmonds_Karp());
    }
    return 0;
}