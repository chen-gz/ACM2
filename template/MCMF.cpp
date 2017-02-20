#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<functional>
using namespace std;

#define N 1000
#define INF 100000000

struct Edge
{
    int from,to,cap,flow,cost;
    Edge(int u,int v,int ca,int f,int co):from(u),to(v),cap(ca),flow(f),cost(co){};
};

struct MCMF
{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[N];
    int inq[N];//�Ƿ��ڶ�����
    int d[N];//����
    int p[N];//��һ����
    int a[N];//�ɸĽ���

    void init(int n)//��ʼ��
    {
        this->n=n;
        for(int i=0;i<n;i++)
            G[i].clear();
        edges.clear();
    }

    void addedge(int from,int to,int cap,int cost)//�ӱ�
    {
        edges.push_back(Edge(from,to,cap,0,cost));
        edges.push_back(Edge(to,from,0,0,-cost));
        int m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool SPFA(int s,int t,int &flow,int &cost)//Ѱ����С���õ�����·��ʹ������ͬʱ�޸�ԭflow,cost
    {
        for(int i=0;i<n;i++)
            d[i]=INF;
        memset(inq,0,sizeof(inq));
        d[s]=0;inq[s]=1;p[s]=0;a[s]=INF;
        queue<int> Q;
        Q.push(s);
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            inq[u]--;
            for(int i=0;i<G[u].size();i++)
            {
                Edge& e=edges[G[u][i]];
                if(e.cap>e.flow && d[e.to]>d[u]+e.cost)//����������ҿɱ��
                {
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=G[u][i];
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to])
                    {
                        inq[e.to]++;
                        Q.push(e.to);
                    }
                }
            }
        }
        if(d[t]==INF) return false;//��㲻�ɴ����˳�
        flow+=a[t];
        cost+=d[t]*a[t];
        int u=t;
        while(u!=s)//��������ߺͷ����
        {
            edges[p[u]].flow+=a[t];
            edges[p[u]^1].flow-=a[t];
            u=edges[p[u]].from;
        }
        return true;
    }

    int MincotMaxflow(int s,int t)
    {
        int flow=0,cost=0;
        while(SPFA(s,t,flow,cost));
        return cost;
    }
};


int main()
{
    MCMF mcmf;
    return 0;
}