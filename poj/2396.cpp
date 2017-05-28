//POJ 2396 有上下界的可行流
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

#define N 400
#define INF 1000000000

using namespace std;

int cap[N][N],up[N][N],down[N][N],flow[N][N],in[N],out[N];
int q[N*100],layer[N];
int n,m,T,S,TT,SS,sum,cas;

inline void read()
{
    memset(down,0,sizeof down);
    memset(flow,0,sizeof flow);
    memset(cap,0,sizeof cap);
    memset(in,0,sizeof in);
    memset(out,0,sizeof out);
    memset(up,0,sizeof up);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            up[i][j+n]=INF;
    S=0; T=n+m+1;
    for(int i=1,a;i<=n;i++)
    {
        scanf("%d",&a);
        up[S][i]=down[S][i]=a;
    }
    for(int i=1,a;i<=m;i++)
    {
        scanf("%d",&a);
        up[i+n][T]=down[i+n][T]=a;
    }
    int qu; char str[4]; scanf("%d",&qu);
    for(int i=1,a,b,c;i<=qu;i++)
    {
        scanf("%d%d%s%d",&a,&b,str,&c);
        if(a==0&&b==0)
        {
            if(str[0]=='=')
            { 
                for(int j=1;j<=n;j++)
                    for(int k=1;k<=m;k++)
                    {
                        down[j][k+n]=c;
                        up[j][k+n]=c;
                    }
            }
            else if(str[0]=='>')
            {
                for(int j=1;j<=n;j++)
                    for(int k=1;k<=m;k++)
                        down[j][k+n]=max(c+1,down[j][k+n]);
            }
            else
            {
                for(int j=1;j<=n;j++)
                    for(int k=1;k<=m;k++)
                        up[j][k+n]=min(c-1,up[j][k+n]);
            }
        }
        else if(a==0&&b!=0)
        {
            if(str[0]=='=')
            {
                for(int j=1;j<=n;j++)
                {
                    down[j][b+n]=c;
                    up[j][b+n]=c;
                }
            }
            else if(str[0]=='>')
            {
                for(int j=1;j<=n;j++)
                    down[j][b+n]=max(c+1,down[j][b+n]);
            }
            else
            {
                for(int j=1;j<=n;j++)
                    up[j][b+n]=min(c-1,up[j][b+n]);
            }
        }
        else if(b==0&&a!=0)
        {
            if(str[0]=='=')
            {
                for(int j=1;j<=m;j++)
                {
                    down[a][j+n]=c;
                    up[a][j+n]=c;
                }
            }
            else if(str[0]=='>')
            {
                for(int j=1;j<=m;j++)
                    down[a][j+n]=max(c+1,down[a][j+n]);
            }
            else
            {
                for(int j=1;j<=m;j++)
                    up[a][j+n]=min(c-1,up[a][j+n]);
            }
        }
        else if(a!=0&&b!=0)
        {
            if(str[0]=='=')
            {
                down[a][b+n]=c;
                up[a][b+n]=c;
            }
            else if(str[0]=='>') down[a][b+n]=max(c+1,down[a][b+n]);
            else up[a][b+n]=min(c-1,up[a][b+n]);
        }
    }
}

inline bool bfs(int st,int ed)
{
    memset(layer,-1,sizeof layer);
    int h=1,t=2,sta;
    q[1]=st; layer[st]=0;
    while(h<t)
    {
        sta=q[h++];
        for(int i=0;i<=ed;i++)
            if(cap[sta][i]>0&&layer[i]<0)
            {
                layer[i]=layer[sta]+1;
                q[t++]=i;
            }
    }
    return layer[ed]!=-1;
}

inline int find(int u,int t,int cur_flow)
{
    if(u==t) return cur_flow;
    int res=0,tmp;
    for(int i=0;i<=t&&res<cur_flow;i++)
        if(cap[u][i]>0&&layer[i]==layer[u]+1)
        {
            tmp=find(i,t,min(cur_flow-res,cap[u][i]));
            cap[u][i]-=tmp; cap[i][u]+=tmp; 
            flow[u][i]+=tmp; flow[i][u]-=tmp;
            res+=tmp;
        }
    if(!res) layer[u]=-1;
    return res;
}

inline int dinic(int s,int t)
{
    int ans=0;
    while(bfs(s,t)) ans+=find(s,t,INF);
    return ans;
}

inline void go()
{
    sum=0;
    SS=T+1; TT=SS+1;
    for(int i=0;i<=T;i++)
        for(int j=0;j<=T;j++)
        {
            cap[i][j]=up[i][j]-down[i][j];
            in[j]+=down[i][j];
            out[i]+=down[i][j];
            sum+=down[i][j];
        }
    for(int i=0;i<=T;i++)
    {
        cap[SS][i]=in[i];
        cap[i][TT]=out[i];
    }
    cap[T][S]=INF;
    int ans=dinic(SS,TT);
    if(ans!=sum)
    {
        printf("IMPOSSIBLE\n");
        return;
    }
    cap[T][S]=cap[S][T]=0;
    ans=dinic(S,T);
    for(int i=1;i<=n;i++)
    {
        printf("%d",flow[i][1+n]+down[i][1+n]);
        for(int j=2;j<=m;j++)
            printf(" %d",flow[i][j+n]+down[i][j+n]);
        puts("");
    }
    puts("");
}

int main()
{
    scanf("%d",&cas);
    while(cas--) read(),go();
    return 0;
}