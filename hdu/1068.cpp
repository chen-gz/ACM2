/*HDU1068匈牙利算法
思考过程：
1、对没有好感的点之间连一条边。最后求最大团。
对有好感度的点之间连一条无向边。最后求最大独立集。
最大团是NP问题。
这道题目因为特殊性：一条边连接的是一男一女，所以必然能用红蓝着色，分成两个集合，所以这也暗示了这个图是一个二分图
这样我们用2中的思路来看，对于一条边连接的两个点，必然不能划分到一个集合中去。
也就像在红蓝染色过程中，我们只能选择（尽可能）被染成同一种颜色的点。
所以就是个求二分图最大独立点集（最大匹配）的问题.
使用匈牙利算法，复杂度为O(MN)
important：最大独立点集=最小覆盖路径= 顶点数 - 最大二分匹配/2
匈牙利算法：
伪代码：from byvoid
bool 寻找从k出发的对应项出的可增广路
{
while (从邻接表中列举k能关联到顶点j)
{
if (j不在增广路上)
{
把j加入增广路;
if (j是未盖点 或者 从j的对应项出发有可增广路)
{
修改j的对应项为k;
则从k的对应项出有可增广路,返回true;
}
}
}
则从k的对应项出没有可增广路,返回false;
}

void 匈牙利hungary()
{
for i->1 to n
{
if (则从i的对应项出有可增广路)
匹配数++;
}
输出 匹配数;
}
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <set>
#include <stack>
#include <vector>
#define maxn 510
using namespace std;

vector<int> G[maxn];
int match[maxn];//记录点的对应项
bool visit[maxn];//记录点是否在增广路上

int n;
/* 7
0: (3) 4 5 6*/
void read(){
	for(int i=1;i<=n;i++)
		G[i].clear();
	for(int i=1;i<=n;i++){
		int a,k,b;
		scanf("%d:  (%d)",&a,&k);
		a++;
		for(int j=0;j<k;j++){
			scanf("%d",&b);
			b++;
			G[a].push_back(b);
		}
	}
	return ;
}
bool dfs(int s)//找到从s点出发的可增广路
{
	for(int i=0;i<G[s].size();i++){
		int v=G[s][i];
		if (!visit[v]){
			visit[v]=true;
			if (match[v]==0 || dfs(match[v])){//说明v对应的项有增广路
				match[v]=s;//修改v的对应项（即互斥点）是s
				return true;
			}
		}
	}
	return false;
}

int hungary(){
	int ans=0;
	memset(match,0,sizeof(match));//清空匹配
	for(int i=1;i<=n;i++){
		memset(visit,0,sizeof(visit));//注意清空增广路
		if (dfs(i))
			ans++;
	}
	return ans;
}

int main(){
	while(cin>>n){
		read();
		printf("%d\n",n-hungary()/2);
		//最大匹配
	}
	return 0;
}