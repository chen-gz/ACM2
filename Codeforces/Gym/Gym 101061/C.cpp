#include <bits/stdc++.h>
using namespace std;
#define MaxN 100000
#define MaxM MaxN*10
#define INF 1000000000

int Map[110][110];
int cost[110][110];
int N, M;
int S, T;

int tot[110];
int walk[110];
int vis[110];
struct cmp
{
    bool operator() (int &a, int &b)
    {
        if (walk[a] == walk[b])
            return tot[a] > tot[b];
        return walk[a] > walk[b];
    }
};

void SPFA()
{
    for (int i = 0; i <= N; i++)
    {
        tot[i] = INF;
        walk[i] = INF;
        vis[i] = 0;
    }
    tot[S] = 0;
    walk[S] = 0;
    vis[S] = 1;
    priority_queue<int, vector<int>, cmp > q;
    q.push(S);
    while (!q.empty())
    {
        int tmp = q.top();
        q.pop();
        vis[tmp] = 0;
        for (int i = 1; i <= N; i++)
        {
            if ( Map[tmp][i] == 2)
            {
                if (walk[i] > walk[tmp])
                {
                    tot[i] = tot[tmp] + cost[tmp][i];
                    walk[i] = walk[tmp];
                    if (!vis[i])
                    {
                        q.push(i);
                        vis[i] = 1;
                    }
                }
                if (walk[i] == walk[tmp])
                {
                    if (tot[i] > tot[tmp] + cost[tmp][i])
                    {
                        tot[i] = tot[tmp] + cost[tmp][i];
                        if (!vis[i])
                        {
                            q.push(i);
                            vis[i] = 1;
                        }
                    }
                }
            }

            if (Map[tmp][i] == 1)
            {
                if (walk[i] > walk[tmp] + cost[tmp][i])
                {
                    walk[i] = walk[tmp] + cost[tmp][i];
                    tot[i] = tot[tmp] + cost[tmp][i];
                    if (!vis[i])
                    {
                        q.push(i);
                        vis[i] = 1;
                    }
                }
                if (walk[i] == walk[tmp] + cost[tmp][i] )
                {
                    if (tot[i] > tot[tmp] + cost[tmp][i])
                    {
                        tot[i] = tot[tmp] + cost[tmp][i];
                        if (!vis[i])
                        {
                            q.push(i);
                            vis[i] = 1;
                        }
                    }
                }
            }
        }
    }
}

void init()
{
    memset(Map, 0, sizeof(Map));
    memset(cost, 0, sizeof(cost));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        init();
        scanf("%d%d", &N, &M);
        for (int i = 0; i < M; i++)
        {
            int a, b, c, k;
            scanf("%d%d%d%d", &a, &b, &c, &k);
            if (Map[a][b] < k)
            {
                Map[a][b] = Map[b][a] = k;
                cost[a][b] = cost[b][a] = c;
            }
            if (Map[a][b] == k)
            {
                if (cost[a][b] > c)
                    cost[a][b] = cost[b][a] = c;
            }
        }
        scanf("%d%d", &S, &T);
        SPFA();
        int ans = tot[T];
        if (ans != INF)
            cout << walk[T] << " " << tot[T] << endl;
        else
            cout << -1 << endl;

    }


}