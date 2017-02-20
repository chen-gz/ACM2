//POJ_1273 Drainage Ditches
//dinic算法
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define INT_MAX       2147483647 
/* maximum (signed) int value */
const int MAX=220;
int n,m,src,des;
//src起始点
//des结束点
int map[MAX][MAX],dep[MAX];
//dep[i]表示当前点到起点src的层数

int BFS(){
	queue<int> q;
	while(!q.empty())
		q.pop();
	memset(dep,-1,sizeof(dep));
	dep[src]=0;
	q.push(src);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v=1;v<=m;v++)
			if(map[u][v]>0 && dep[v]==-1){//如果可以到达且还没有访问
				dep[v]=dep[u]+1;
				q.push(v);
			}
	}
	return dep[des]!=-1;
}

int DFS(int u,int minx){//查找路径上的最小的流量
	if(u==des)
		return minx;
	int tmp;
	for(int v=1;v<=m;v++)
		if(map[u][v]>0 && dep[v]==dep[u]+1 && (tmp=DFS(v,min(minx,map[u][v])))){
			map[u][v] -=tmp;//正向减少
			map[v][u] +=tmp; //反向增加
			return tmp;
		}
		return 0;
}

int Dinic(){
	int ans=0,tmp;
	while(BFS()){
		while(1){
			tmp=DFS(1,INT_MAX);
			if(tmp==0)
				break;
			ans+=tmp;
		}
	}
	return ans;
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		memset(map,0,sizeof(map));
		int u,v,w;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&u,&v,&w);
			map[u][v]+=w;//防止有重边
		}
		src=1;des=m;
		printf("%d\n",Dinic());
	}
	return 0;
}
