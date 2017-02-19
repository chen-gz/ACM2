//#include<iostream>
//#include<cstdio>
//#include<functional>
//#include<vector>
//#include<queue>
//#define LL long long
//using namespace std;
//const int INF=(1<<30);
//const int maxn=100000+5;
//priority_queue<int,vector<int>,greater<int> > pq;
//int a[maxn];
//int main()
//{
//    int n;
//    LL sum=0;
//    scanf("%d",&n);
//    for(int i=1;i<=n;i++) {scanf("%d",a+i);sum+=a[i];}
//    for(int i=1;i<=n;i++)
//    {
//        pq.push(a[i]);
//        if(i%2==0) pq.pop();
//    }
//    LL ans=0;
//    while(!pq.empty()) {ans+=pq.top();pq.pop();}
//    printf("%I64d %I64d\n",ans,sum-ans);
//}