/*
分析：这题明显要用唯一分解定理来做。gcd(x,y,x)=G,lcm(x,y,z)=L;
x=p1^a1*p2^a2……ps^as;
y=p1^b1*p2^b2……ps^bs;
z=p1^c2*p2^c2……ps^cs;
G,L已知，满足条件：
G=p1^min(a1,b1,c1)……ps^min(as,bs,cs)=p1^e1……ps^es
L=p1^max(a1,b1,c1)……ps^max(as,bs,cs)=p1^h1……ps^hs
则满足 ei=min(ai,bi,ci) hi=max(ai,bi,ci),考虑组合数。
考虑有序数对，对于每个(ei,hi) ,让 (x,y,z)固定两个数，让一个数变化有 6种，即 A(3,2)=6，每一种有(hi-ei+1)种。
然后考虑重复情况，每次，只要(x,y,z)中只出现ei,hi的情况重复,总共重复6次.即 6*(hi-ei+1)-6=6*(hi-ei)种.
即 6*(h1-e1)*6(h2-e2)……，由于是幂指数相减，考虑L/G就可。如果不能整除即没有(x,y,z)满足条件。公式推出，题目就好做了！
*/
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=1e7+5;
bool vis[maxn];
int  prime[maxn/10],factor[maxn],len=0;

void is_prime()//素数打表
{
    for(int i=2;i<maxn;i++)
    {
        if(!vis[i])
        {
            prime[len++]=i;
            for(int j=i+i;j<maxn;j+=i)
            {
                vis[j]=1;
            }
        }
    }
}
void getprimefactor(int nn)//得到素数幂指数
{
    int cas=0;
    for(int i=0;i<len&&prime[i]*prime[i]<=nn;i++)
    {
            while(nn%prime[i]==0)
            {
                factor[cas]++;
                nn/=prime[i];
            } 
          if(factor[cas])
          cas++;
    }
    if(nn>1)
    factor[cas]=1;
}

int main()
{
    is_prime(); 
    int t,g,l;
     scanf("%d",&t);
     while(t--)
     {
        memset(factor,0,sizeof(factor));
        int sum=1;
        scanf("%d %d",&g,&l);
        if(l%g)
        {
            printf("0\n");
            continue;
         }
         int k=l/g;
         getprimefactor(k);

         for(int i=0;;i++)
         {
            if(!factor[i])
            break;
            sum*=factor[i];
            sum*=6;
         }
         printf("%d\n",sum);
      } 
      return 0;
}