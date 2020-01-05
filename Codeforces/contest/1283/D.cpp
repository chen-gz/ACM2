#include <bits/stdc++.h>

using namespace std;

#define N int(2e5) + 10
int a[N];
int b[N];
map<int, int> s;
queue<int> q;
long long ans = 0;
int cnt =0;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		q.push(a[i]);
		s[a[i]] = 0;
	}
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		if(s.count(top+1) == 0){
			ans += s[top] +1;
			q.push(top+1);
			s[top+1] = s[top] +1;
			b[cnt] = top +1;
			cnt += 1;
		}
		if ( cnt == m){
			break;
		}
		if(s.count(top-1) == 0){
			ans += s[top] +1;
			q.push(top-1);
			s[top-1] = s[top] +1;
			b[cnt] = top -1;
			cnt += 1;
		}
		if ( cnt == m){
			break;
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<m;i++){
		cout<<b[i] <<" ";
	}
	cout<<endl;

	return 0;
}