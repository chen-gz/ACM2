#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	int n; cin>>n;
	int i=1;
	int sum = 0;
	while(sum<=n) {
		sum += i; i++;
	}
	i--; sum -=i;
	i--; sum -=i;
	cout<<i<<endl;
	for(int j=1; j<i; j++)
		cout<<j<<" ";
	cout<<n-sum<<endl;
	return 0;
}
