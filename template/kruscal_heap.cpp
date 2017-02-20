// ±º‰∏¥‘”∂»O(mlog(n))
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define F(a,b,c) for(int a=b;a<=c;a++)
#define M(a,b) memset(a,b,sizeof(a))
#define pw(x) ((x)*(x))
using namespace std;
struct P
{
	int x,y;
}p[502];
struct Q
{
	int a,b,l;
}heap[250002],now;
int n,m,T,size,aa,bb,fa[502];
inline bool comp(int a,int b)
{
	return heap[a].l<heap[b].l;
}
void up(int p)
{
	if((p>1)&&(comp(p,p/2)))
	{
		swap(heap[p],heap[p/2]);
		up(p/2);
	}
}
void down(int p)
{
	int temp=p;
	if((p*2<=size)&&(comp(p*2,temp)))temp=p*2;
	if((p*2<size)&&(comp(p*2+1,temp)))temp=p*2+1;
	if(temp!=p)
	{
		swap(heap[p],heap[temp]);
		down(temp);
	}
}
inline void add(int a,int b)
{
	size++;
	heap[size].a=a;
	heap[size].b=b;
	heap[size].l=pw(p[a].x-p[b].x)+pw(p[a].y-p[b].y);
	up(size);
}
int find(int p)
{
	if(fa[p]!=p)fa[p]=find(fa[p]);
	return fa[p];
}
int main()
{
	scanf("%d",&T);while(T--)
	{
		size=0;
		scanf("%d %d",&m,&n);
		F(i,1,n)fa[i]=i;
		F(i,1,n)
		{
			scanf("%d %d",&p[i].x,&p[i].y);
			F(j,1,i-1)add(i,j);
		}
		for(int i=1;(i<=n-m)&&(size);)
		{
			now=heap[1];heap[1]=heap[size];size--;down(1);
			aa=find(now.a);bb=find(now.b);
			if(aa==bb)continue;
			//printf("%d %d\n",now.a,now.b);
			fa[aa]=bb;
			i++;
		}
		printf("%.2lf\n",sqrt((double)now.l));
	}
	return 0;
}
