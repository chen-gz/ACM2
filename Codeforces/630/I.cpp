/*
列举出几组例子可以找到规律，因为n辆车是连续的（我们将其看做一个整体）所以我们应当对m-n+1个车位进行全排列
*/
#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<string>
#include<math.h>
#include<algorithm>
#define LL long long
#define PI atan(1.0)*4
#define DD double
#define MAX 30000
#define mod 100
#define dian 1.000000011
#define INF 0x3f3f3f
using namespace std;
int main()
{
    LL n,m,j,i,t,k;
    LL sum,sum1,sum2;
    while(scanf("%lld",&n)!=EOF)
    {
        m=2*n-2;
        k=m-n;
        sum1=2*3*pow(4,k); 
        sum2=(k-1)*3*3*pow(4,k-1);
        sum=sum1+sum2;
        printf("%lld\n",sum);
    }
    return 0;
}