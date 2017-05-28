//hdu2296Ring
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
using namespace std;
int N,M;
const int maxnode=1000+100;
const int sigma_size=26;
inline string better(string a,string b)
{
	if(a=="")
		return b;
	if(a.size()!=b.size())
		return a.size()<b.size() ? a:b;
	return a<b? a:b;
}
struct AC_Automata
{
	int ch[maxnode][sigma_size];
	int match[maxnode];
	int f[maxnode];
	int sz;
	int dp[maxnode][50+10];
	string path[maxnode][50+10];
	int ans;
	string res;
	void init()
	{
		sz=1;
		memset(ch[0],0,sizeof(ch[0]));
		match[0]=f[0]=0;
	}
	void insert(char *s,int v)
	{
		int n=strlen(s),u=0;
		for(int i=0;i<n;i++)
		{
			int id=s[i]-'a';
			if(ch[u][id]==0)
			{
				ch[u][id]=sz;
				memset(ch[sz],0,sizeof(ch[sz]));
				match[sz++]=0;
			}
			u=ch[u][id];
		}
		match[u]=v;
	}
	void getFail()
	{
		queue<int> q;
		for(int i=0;i<sigma_size;i++)
		{
			int u=ch[0][i];
			if(u)
			{
				f[u]=0;
				q.push(u);
			}
		}
		while(!q.empty())
		{
			int r=q.front();q.pop();
			for(int i=0;i<sigma_size;i++)
			{
				int u=ch[r][i];
				if(!u){ ch[r][i]=ch[f[r]][i]; continue; }
				q.push(u);
				int v=f[r];
				while(v && ch[v][i]==0) v=f[v];
				f[u]=ch[v][i];
				match[u] += match[f[u]];
			}
		}
	}
	void solve()
	{
		ans=0;
		res="";
		for(int i=0;i<sz;i++)
			for(int j=0;j<=N;j++)
			{
				dp[i][j]=-1;
				path[i][j]="";
			}
			dp[0][0]=0;
			for(int len=0;len<N;len++)//当前走的长度
				for(int k=0;k<sz;k++)if(dp[k][len]!=-1)//当前所在的节点
				{
					for(int j=0;j<sigma_size;j++)//下一步走的方向
						if(dp[ch[k][j]][len+1] <= dp[k][len]+match[ch[k][j]])
						{
							char temp='a'+j;
							if(dp[ch[k][j]][len+1] < dp[k][len]+match[ch[k][j]])
							{
								dp[ch[k][j]][len+1] = dp[k][len]+match[ch[k][j]];
								path[ch[k][j]][len+1] = path[k][len]+temp;
							}
							else
							{
								path[ch[k][j]][len+1] = better(path[ch[k][j]][len+1],path[k][len]+temp);
							}

							if(ans < dp[ch[k][j]][len+1])
							{
								ans = dp[ch[k][j]][len+1];
								res = path[ch[k][j]][len+1];
							}
							else if(ans == dp[ch[k][j]][len+1])
								res = better(res,path[ch[k][j]][len+1]);
						}
				}
	}
}ac;
char str[100+10][10+5];
int val[100+10];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ac.init();
		scanf("%d%d",&N,&M);
		for(int i=0;i<M;i++)
			scanf("%s",str[i]);
		for(int i=0;i<M;i++)
		{
			scanf("%d",&val[i]);
			ac.insert(str[i],val[i]);
		}
		ac.getFail();
		ac.solve();
		if(ac.ans==0)
			printf("\n");
		else
			cout<<ac.res<<endl;
	}
	return 0;
}
