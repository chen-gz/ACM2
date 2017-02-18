#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	long long a,b,k; cin>>k>>a>>b;
	long long ans =a /k+ b/k;
	if((a/k==0 && b%k!=0)||(b/k==0 && a%k!=0)||ans==0)
		cout<<"-1";
	else
		cout<<ans;
}
