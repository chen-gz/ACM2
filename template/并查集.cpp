//���鼯,��̯��ʱ�临�Ӷȱ�O(log n)����
#define maxn 111111
int fa[maxn];//par[i]��ʾi�ĸ��׵ı��
int deep[maxn];//deep[i]��ʾi�������ĸ߶�
void init(int n)//��ʼ��n��Ԫ��
{
    for(int i=0;i<=n;i++)
    {
        fa[i]=i;
        deep[i]=0;
    }
}
int find(int x)//��ѯ���ĸ�
{
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
void unite(int x,int y)//�ϲ�x��y�����ļ���
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
bool same(int x,int y)//�ж�x��y�Ƿ�����ͬһ������
{
    return find(x)==find(y);
}
