#include <bits/stdc++.h>
using namespace std;
int  main(int argc, char const *argv[]) {
	long long n,k;
	cin>>n>>k;
	long long cnt=0;
	long long a[100000];
	memset(a,0,sizeof(a));
	a[cnt++]=1;
	for(long long i=2; i<=n; i++) {
		if(n%i==0) {
			a[cnt++]=i;
		}
	}
	if(a[k-1]==0) {
		cout<< -1<<endl;
	}
	else
		std::cout << a[k-1] << '\n';
	return 0;
}
