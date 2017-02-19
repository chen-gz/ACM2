#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	int max = -1;
	int a[100];
	for(int i =0; i<n; i++) {
		cin>>a[i];
		if(max<a[i]) {
			max = a[i];
		}
	}
	int ans =0;
	for(int i=0; i<n; i++) {
		ans += max - a[i];
	}
	cout<<ans<<endl;
	return 0;
}
