#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 200 
using namespace std;

char mapn[N+3][103];
int head[N+3],tol,dp[N+3][2],dup[N+3][2];

struct node
{
	int front,to,next;
}edge[2*N+3];

void add(int a,int b)
{
	edge[tol].front = a;
	edge[tol].to = b;
	edge[tol].next = head[a];
	head[a] = tol;
	tol ++;
}

void dfs(int root)
{
	int u;
	dp[root][0] = 0;
	dp[root][1] = 1;
	dup[root][0] = 1;
	dup[root][1] = 1;
	for(int j = head[root];j != -1;j = edge[j].next)
	{
		u = edge[j].to;
		dfs(u);
		dp[root][0] += max(dp[u][0],dp[u][1]);
		dp[root][1] += dp[u][0];
		if(dp[u][0] > dp[u][1] && dup[u][0] == 0)
		    dup[root][0] = 0;
		else if(dp[u][1] > dp[u][0] && dup[u][1] == 0)
		    dup[root][1] = 0;
		else if(dp[u][1] == dp[u][0])
		    dup[root][0] = 0;
		if(dup[u][0] == 0)
		    dup[root][1] = 0;
	}
}

int main()
{
	int cas;
	char str1[103],str2[103];
	while(scanf("%d",&cas) != EOF && cas)
	{
		scanf("%s",mapn[1]);
		int k = 1;
		tol = 0;
		memset(head,-1,sizeof(head));
		memset(dp,0,sizeof(dp));
		int ans1,ans2;
		for(int i = 1;i < cas;i ++)
		{
			scanf("%s%s",str1,str2);
			ans1 = -1;
			ans2 = -1;
			for(int j = 1;j <= k;j ++)
			{
				if(!strcmp(mapn[j],str1))
				    ans1 = j;
				if(!strcmp(mapn[j],str2))
				    ans2 = j;
			}
			if(ans1 == -1)
			{
				k ++;
				strcpy(mapn[k],str1);
				ans1 = k;
			}
			if(ans2 == -1)
			{
				k ++;
				strcpy(mapn[k],str2);
				ans2 = k;
			}
			add(ans2,ans1);
		}
		dfs(1);
		if(dp[1][0] > dp[1][1] && dup[1][0] == 1)
		    printf("%d Yes\n",dp[1][0]);
		else if(dp[1][1] > dp[1][0] && dup[1][1] == 1)
		    printf("%d Yes\n",dp[1][1]);
		else
		    printf("%d No\n",max(dp[1][0],dp[1][1]));
	}
	return 0;
}
/*
6
Jason
Jack Jason
Joe Jack
Jill Jason
John Jack
Jim Jill
2
Ming
Cho Ming
0
*/
