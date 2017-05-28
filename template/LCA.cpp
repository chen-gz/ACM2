//LCA 
/*创建对象；
先调用addedge函数；构造图；
然后调用work函数；//参数为，两个结点 和 最大父节点。
*/
#include <iostream>
#include <algorithm>
using namespace std;
class LAC{
#pragma region def
#ifndef INT_MAX
#define INT_MAX 2147483647
#endif
#ifndef POINT_NUM
#define POINT_NUM 20000
#endif
#ifndef EDGE_NUM
#define EDGE_NUM 20000
#endif
#pragma endregion
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
		if(!has_e)//不是重边
		{
			edge[edgenum].from = _from;
			edge[edgenum].to = _to;
			edge[edgenum].weight += _w;
			edge[edgenum].next=head[_from];
			head[_from]=edgenum++;
		}
	};
#pragma endregion
	//deep[]初始化为0；
	//p[i][j]表示i结点的第2^j祖先
private:
	int deep[POINT_NUM];
	int p[POINT_NUM][30];
	inline void dfs(int u)
	{
		//1. DFS预处理出所有节点的深度和父节点
		int i;
		for(i=head[u];i!=-1;i=edge[i].next)  {  
			//遍历与u相连的结点
			if (!deep[edge[i].to]){			
				deep[edge[i].to] = deep[u]+1;
				p[edge[i].to][0] = u; //p[x][0]保存x的父节点为u;
				dfs(edge[i].to);
			}
		}
	}
	void LCA(){
		memset(head,-1,sizeof(head));
		for(int i=0;i<POINT_NUM;i++){
			edge[i].weight=0;
		}
		memset(p,-1,sizeof(p));
		memset(deep,0,sizeof(deep));

	}
	void init()
	{
		/*
		2. 初始各个点的2^j祖先是谁 ,
		其中 2^j (j =0...log(该点深度))倍祖先，
		1倍祖先就是父亲，2倍祖先是父亲的父亲......。
		*/
		int i,j;
		//p[i][j]表示i结点的第2^j祖先
		for(j=1;(1<<j)<=POINT_NUM-1;j++)
			for(i=1;i<=POINT_NUM-1;i++)
				if(p[i][j-1]!=-1)
					p[i][j]=p[p[i][j-1]][j-1];//i的第2^j祖先就是i的第2^(j-1)祖先的第2^(j-1)祖先
	}
	int lca(int a,int b)//最近公共祖先
	{
		/*
		3.从深度大的节点上升至深度小的节点同层，
		如果此时两节点相同直接返回此节点，即lca。

		否则，利用倍增法找到最小深度的 p[a][j]!=p[b][j]，
		此时他们的父亲p[a][0]即lca。
		*/
		int i,j;
		if(deep[a]<deep[b])
			swap(a,b);
		for(i=0;(1<<i)<=deep[a];i++);
		i--;
		//使a，b两点的深度相同
		for(j=i;j>=0;j--)
			if(deep[a]-(1<<j)>=deep[b])
				a=p[a][j];
		if(a==b)return a;
		//倍增法，每次向上进深度2^j，找到最近公共祖先的子结点
		for(j=i;j>=0;j--){
			if(p[a][j]!=-1&&p[a][j]!=p[b][j]){
				a=p[a][j];
				b=p[b][j];
			}
		}
		return p[a][0];
	}
public:
	void addedge(int _from,int _to,int _weight){
		//双向图，正向权值为_weight;反向权值为0；
		build_edge(edgenum,_from,_to,_weight);
		build_edge(edgenum,_to,_from,0);
	}
	int work(int a ,int b,int father){
		dfs(father);
		init();
		return lca( a, b);
	}
};