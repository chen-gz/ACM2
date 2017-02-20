//poj 1273 Drainage Ditches
//最大流问题
//题意：给定1-n个点，和m条边，以及变的流量，求从1到n的最大流量；
//Ford-Fulkerson算法；
#include<cstdio>
#include<cstring>
#define INT_MAX       2147483647  
/* maximum (signed) int value */
//有的编译器没有定义，poj就没有，hust有。。无奈；
const int MAX =600;
int from[MAX],next[MAX],to[MAX],flow[MAX],arcnum=1;
int vis[MAX];
void addarc(int _from,int _to,int _c){
	next[++arcnum]=from[_from];
	from[_from]=arcnum;
	to[arcnum]=_to;
	flow[arcnum]=_c;
}

int DFS(int u,int t,int minc){
	//起点u，终点t，整条路径中流量最小为minc
	if(u==t)
		return minc;
	vis[u]=1;
	for(int p=from[u];p!=0;p=next[p]){
		int v=to[p];
		if(!vis[v]&&flow[p]>0){

			int f=DFS(v,t,min(minc,flow[p]));
			if(f>0){
				flow[p]-=f;//正向边减去算出的流量 
				flow[p^1]+=f;//逆向边加上算出的流量
				//n为偶自然数，n^1=n+1;(n+1)^1=n;
				//正向边存为偶数；
				return f;
			}
		}
	}
	return 0;
}
int MaxFlow(int s,int t){
	int ans=0;
	while(1){
		memset(vis,0,sizeof(vis));
		int f=DFS(s,t,INT_MAX);
		if(f<=0)//没有增广路
			return ans;
		ans+=f;
	}
}
int main(){
	int n,m,a,b,c;
	while(~scanf("%d%d",&m,&n)){
		memset(from,0,sizeof(from));
		memset(flow,0,sizeof(flow));
		arcnum=1;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&a,&b,&c);
			addarc(a,b,c);//正向边流量为c 
			addarc(b,a,0);//逆向边流量为0 
		}
		printf("%d\n",MaxFlow(1,n));
	}
	return 0;
}