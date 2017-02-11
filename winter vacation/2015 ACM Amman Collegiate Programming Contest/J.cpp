#include <bits/stdc++.h>
using namespace std;
int students[100];
int candy[300];
int main(int argc, char const *argv[]) {
	freopen("input.txt","r",stdin );
	int T; cin>>T;
	while(T--) {
		int n,m; scanf("%d%d\n",&n,&m );
		for(int i =0; i<n; i++) {
			scanf("%d",&students[i]);
		}
		for(int i=0; i<m; i++) {
			scanf("%d",&candy[i] );
		}
		sort(students,students+n);
		sort(candy,candy+m);
		queue<int> cq;
		queue<int> sq;
		int cnt =1;
		int last=students[0];
		for(int i =1; i<n; i++) {
			if(last==students[i]) {
				cnt++;
			}
			else{
				sq.push(cnt);
				cnt =1;
				last = students[i];
			}
		}
		sq.push(cnt);
		cnt =1;
		last=candy[0];
		for(int i =1; i<n; i++) {
			if(last==candy[i]) {
				cnt++;
			}
			else{
				cq.push(cnt);
				cnt =1;
				last = candy[i];
			}
		}
		cq.push(cnt);
		bool can = false;
		while(!cq.empty()) {
			if(cq.front() >= sq.front()) {
				sq.pop();
				if(sq.empty()) {
					can = true;
					break;
				}
			}
			cq.pop();
		}
		if(can) {
			std::cout << "YES" << '\n';
		}
		else
			std::cout << "NO" << '\n';
	}
	return 0;
}
