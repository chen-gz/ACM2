#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<map>
#define LL long long
#define ri(a) scanf("%d",&a)
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int maxn = 1e6 + 6;
int p[maxn];
deque<int> q;
int main() {
	int t;
	ri(t);
	while(t--){
		int temp;
		mem(p); q.clear();
		int n, m;
		ri(n); ri(m);
		for (int i = 1; i <= n; i++){
			scanf("%d", &temp);
			p[i] = p[i - 1] + temp;
			p[n + i] = temp;
		}
		for (int i = 1; i <= n; i++) {
			p[i + n] = p[i + n - 1] + p[i + n];
		}
		int ans = -INT_MAX; int left = 0; int right = 0;
		for (int i = 1; i <= 2 * n; i++) {
			while (!q.empty() && p[q.back()] - p[i-1] > 0) {
				q.pop_back();
			}
			q.push_back(i - 1);
			while (!q.empty() && q.front() < i - m) {
				q.pop_front();
			}
			int tot = p[i]-p[q.front()];
			if (tot > ans) {
				ans = tot;
				left = q.front()+1;
				right = i;
			}
		}
		if (right > n)right -= n;
		if (left > n)left -= n;
		printf("%d %d %d\n", ans, left, right);
	}
}