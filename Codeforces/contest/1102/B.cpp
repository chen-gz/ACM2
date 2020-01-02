#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	int val;
	int pos;
} data[5005];
bool cmp(node a, node b){
	return a.val > b.val;
}
int ans[5005];
int main(){
//    FILE *file = freopen("../input", "r", stdin);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> data[i].val;
		data[i].pos = i;
	}
	sort(data, data + n, cmp);
	bool can = true;
	int maxcnt = 0;
	int cnt = 0;
	ans[data[0].pos] = 0;
	int i;
	for(i=1;i<n;i++){
//		if(i == 0 )
		if(k - maxcnt-1 >= n - i){
			if(k-maxcnt-2 > n-i )
				can = false;
			break;
		}
		if(data[i].val == data[i-1].val){
			ans[data[i].pos] = ++cnt;
			maxcnt = max(maxcnt,cnt);
		}
		else {
			cnt = 0;
			ans[data[i].pos] = cnt;
		}
	}
	if(i < n && can){
		for(;i<n;i++) {
            ans[data[i].pos] = ++maxcnt;
        }
	}
	if(!can || maxcnt >= k){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++){
			cout<<ans[i]+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}
