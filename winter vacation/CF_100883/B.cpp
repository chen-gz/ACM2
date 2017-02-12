#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	freopen("input.txt","r",stdin);
	int T; cin>>T;
	while(T--) {
		int minx = 1010;
		int miny = 1010;
		int maxx = -1010;
		int maxy= -1010;
		int n; scanf("%d",&n);
		for(int i=0; i<n; i++) {
			for(int i=0; i<4; i++) {
				int a; int b; scanf("%d %d",&a,&b );
				minx = min(minx,a);
				maxx = max(maxx,a);
				miny = min(miny,b);
				maxy = max(maxy,b);
			}
		}
		printf("%d\n",(maxy-miny)*(maxx-minx) );
	}
	return 0;
}
