#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	//freopen("input.txt","r",stdin);
	int T; cin>>T;
	int num[15];
	while(T--) {
		int n; int tol;
		scanf("%d%d",&n,&tol );
		for(int i=0; i<n; i++) {
			scanf("%d",&num[i]);
		}
		sort(num,num+n);
		int ans =0;
		int have[15];
		int have_num=0;
		int check_sum;
		for(int i=0; i<(1<<n); i++) {
			have_num  =0;
			check_sum = 0;
			for(int j=0; j<n; j++) {
				int temp = 1<<j;
				if(i&temp) {
					have[have_num++]=num[i];
					check_sum += num[i];
				}
				if(check_sum >= tol && check_sum - have[0] <= check_sum) {
					if(ans < have_num)
						ans = have_num;
				}
			}
		}
		cout<<ans-1<<endl;
	}
	return 0;
}
