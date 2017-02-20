//HDU_3183_A Magic Lamp(
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1100;
char str[N];//输入的数字字符串
int res[N];//结果
int minsum[N][20];//存下标
void rmq();
int mmin(int l,int r);
int n;
int Min(int a,int b){
	//比较函数
	return str[a]<=str[b]?a:b;
}

void init(){
	for(int i=0;i<n;i++){
		minsum[i][0]=i;
	}
	return ;
}
void rmq()
{
	int k=(int)(log(n*1.0)/log(2.0));
	for(int j=1;j<=k;j++)
		for(int i=0;i+(1<<j)<=n;i++)
			minsum[i][j]=Min(minsum[i][j-1],minsum[i+(1<<(j-1))][j-1]);
			return ;
}
int mmin(int l,int r)
{
	int k=(int)(log(r-l+1)*1.0/log(2.0));
	return Min(minsum[l][k],minsum[r-(1<<k)+1][k]);
}
int main()
{
	int m;
	while(~scanf("%s %d",str, &m))
	{
		n=strlen(str);
		init();
		rmq();
		m=n-m;
		int p=0, num=0;
		while(m--)
		{
			p=mmin(p,n-m-1);
			res[num++]=(str[p]-'0');
			p++;
		}
		int i;
		for(i=0;i<num;i++)
		{
			if(res[i]!=0)
			{
				break;
			}
		}
		if(i==num)
		{
			printf("0\n");
			continue;
		}
		for(;i<num;i++)
		{
			printf("%d",res[i]);
		}
		printf("\n");
	}
	return 0;
}