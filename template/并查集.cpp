//并查集,均摊后时间复杂度比O(log n)还快
#define maxn 111111
int fa[maxn];//par[i]表示i的父亲的编号
int deep[maxn];//deep[i]表示i所在树的高度
void init(int n)//初始化n个元素
{
    for(int i=0;i<=n;i++)
    {
        fa[i]=i;
        deep[i]=0;
    }
}
int find(int x)//查询树的根
{
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
void unite(int x,int y)//合并x和y所属的集合
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(deep[x]<deep[y]) fa[x]=y;
    else
    {
        fa[y]=x;
        if(deep[x]==deep[y]) deep[x]++;
    }
}
bool same(int x,int y)//判断x和y是否属于同一个集合
{
    return find(x)==find(y);
}
