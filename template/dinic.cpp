/*
需要的头文件:cstring,queue;
需要命名空间：std,Dinic;
可自定义POINT_NUM;默认201;点数
可自定义EDGE_NUM;默认2001;边数
如果在必要情况下，可以将region edge取出；放到class dinic外
*/
// by Wendell
#pragma once
#include<cstring>
#include<queue>
using namespace std;
namespace Dinic
{
#ifndef INT_MAX
#define INT_MAX 2147483647
#endif
#ifndef POINT_NUM
#define POINT_NUM 20000
#endif
#ifndef EDGE_NUM
#define EDGE_NUM 20000
#endif
	class dinic{
	private:
#pragma region edge
		int head[POINT_NUM];
		int edgenum;
		struct node{
			int from;//起点
			int to;//终点
			int next;
			int weight;//权值
		}edge[EDGE_NUM];
		void build_edge(int _edgenum,int _from,int _to,int _w){
			bool has_e=false;
			if(_from==_to)
				return ;
			for(int i=head[_from]; i!=-1; i=edge[i].next){
				//判重边
				if(edge[i].to==_to){
					has_e=true;
					edge[i].weight += _w;
					break;
				}
			}
			if(!has_e)
			{
				edge[edgenum].from = _from;
				edge[edgenum].to = _to;
				edge[edgenum].weight += _w;
				edge[edgenum].next=head[_from];
				head[_from]=edgenum++;
			}
		};
#pragma endregion
	public :
		int lev[POINT_NUM];//点位于的层次
		int start_point;//起点
		int end_point;//终点
		void init(){
			//初始化
			memset(head,-1,sizeof(head));
			for(int i=0;i<POINT_NUM;i++){
				edge[i].weight=0;
			}
		}
		bool bfs(){
			//bfs优化，标记点的层次
			queue<int>q;
			memset(lev, -1, sizeof(lev));
			lev[start_point] = 0;	
			q.push(start_point);
			while(!q.empty()){
				int now = q.front();q.pop();
				int next;
				for(int i = head[now]; i != -1; i = edge[i].next){
					//遍历每一条边
					if(edge[i].weight>0 && lev[next = edge[i].to] < 0){
						lev[next] = lev[now] + 1;
						if(next == end_point)
							return true;
						q.push(next);
					}
				}
			}
			return false;
			//return lev[end_point] != -1;
		}
		int dfs(int u,int minc){
			//dfs求剩余网络最小流量
			if(u==end_point)
				return minc;
			int f;
			for(int p=head[u];p!=-1;p=edge[p].next){
				//遍历每一条边
				int next=edge[p].to;
				if(  edge[p].weight>0 && lev[edge[p].from]+1==lev[next]){
					int f=dfs(next,min(minc,edge[p].weight));
					if(f>0){
						edge[p].weight -=f;
						edge[p^1].weight +=f;
						return f;
						//p为偶自然数，p^1=p+1;(p+1)^1=p;
						//正向边存为偶数；
					}
				}
			}
			return 0;
		}
	public:
		int MaxFlow;
		dinic(){
			edgenum=0;
			init();
			MaxFlow=0;
		}
		void addedge(int _from,int _to,int _weight){
			//双向图，正向权值为_weight;反向权值为0；
			build_edge(edgenum,_from,_to,_weight);
			build_edge(edgenum,_to,_from,0);
		}
		int Work(int _start_point,int _end_point){
			start_point=_start_point;
			end_point=_end_point;
			int cur_flow;
			while(bfs()){
				while(cur_flow = dfs(start_point, INT_MAX))
					MaxFlow += cur_flow;
			}
			return MaxFlow;
		}
		//调用Work函数实现，放回最大流量值；参数为起始点和终止点；
	};
}