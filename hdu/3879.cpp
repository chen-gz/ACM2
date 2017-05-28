// Hdu3879 Base Station
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
//点标 从0开始 F.Init(n) n=最大点标+10
const int N = 200010;
const int M = 500010;
const int INF = ~0u >> 2;
template<class T>
struct Max_Flow {
    int n;
    int Q[N], sign;
    int head[N], level[N], cur[N], pre[N];
    int nxt[M], pnt[M], E;
    T cap[M];
    void Init(int n) {
        this->n = n;
        E = 0;
        std::fill(head, head + n, -1);
    }
    //有向rw 就= 0
    void add(int from, int to, T c, T rw) {
        pnt[E] = to;
        cap[E] = c;
        nxt[E] = head[from];
        head[from] = E++;

        pnt[E] = from;
        cap[E] = rw;
        nxt[E] = head[to];
        head[to] = E++;
    }
    bool Bfs(int s, int t) {
        sign = t;
        std::fill(level, level + n, -1);
        int *front = Q, *tail = Q;
        *tail++ = t; level[t] = 0;
        while(front < tail && level[s] == -1) {
            int u = *front++;
            for(int e = head[u]; e != -1; e = nxt[e]) {
                if(cap[e ^ 1] > 0 && level[pnt[e]] < 0) {
                    level[pnt[e]] = level[u] + 1;
                    *tail ++ = pnt[e];
                }
            }
        }
        return level[s] != -1;
    }
    void Push(int t, T &flow) {
        T mi = INF;
        int p = pre[t];
        for(int p = pre[t]; p != -1; p = pre[pnt[p ^ 1]]) {
            mi = std::min(mi, cap[p]);
        }
        for(int p = pre[t]; p != -1; p = pre[pnt[p ^ 1]]) {
            cap[p] -= mi;
            if(!cap[p]) {
                sign = pnt[p ^ 1];
            }
            cap[p ^ 1] += mi;
        }
        flow += mi;
    }
    void Dfs(int u, int t, T &flow) {
        if(u == t) {
            Push(t, flow);
            return ;
        }
        for(int &e = cur[u]; e != -1; e = nxt[e]) {
            if(cap[e] > 0 && level[u] - 1 == level[pnt[e]]) {
                pre[pnt[e]] = e;
                Dfs(pnt[e], t, flow);
                if(level[sign] > level[u]) {
                    return ;
                }
                sign = t;
            }
        }
    }
    T Dinic(int s, int t) {
        pre[s] = -1;
        T flow = 0;
        while(Bfs(s, t)) {
            std::copy(head, head + n, cur);
            Dfs(s, t, flow);
        }
        return flow;
    }
};
Max_Flow <int>F;
int n, m;
int work(){
    F.Init(n+m+10);
    int from = 0, to = n + m +1, A;
    for(int i = 1; i <= n; i++){
        scanf("%d", &A);
        F.add(i, to, A, 0);
    }
    int u, v, d, all = 0;
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &u, &v, &d);
        all += d;
        F.add(from, n+i, d, 0);
        F.add(n+i, u, INF, 0);
        F.add(n+i, v, INF, 0);
    }
    return all - F.Dinic(from, to);
}
int main(){
    while(cin>>n>>m)
        cout<<work()<<endl;
    return 0;
}
