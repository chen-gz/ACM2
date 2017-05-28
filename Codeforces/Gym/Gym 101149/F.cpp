#include <bits/stdc++.h>
using namespace std;
struct node {
	int x,y,z;
	int pos;
};
node gg[200005];
bool cmp(node a,node b){
	if((a.x>b.x && a.y>b.y)||(a.x>b.x && a.z>b.z) ||(a.y>b.y && a.z>b.z))
		return true;
	return false;
}
int main(int argc, char const *argv[]) {
	freopen("input.txt","r",stdin);
	int n; cin>>n;
	for(int i=0; i<n; i++) {
		scanf("%d %d %d",&gg[i].x,&gg[i].y,&gg[i].z );
		gg[i].pos = i+1;
	}
	sort(gg,gg+n,cmp);
	bool can = true;
	for(int i=0; i<n; i++) {
		if((gg[n-1].x>gg[i].x && gg[n-1].y>gg[i].y)
		   ||(gg[n-1].x>gg[i].x && gg[n-1].z>gg[i].z)
		   ||(gg[n-1].y>gg[i].y && gg[n-1].z>gg[i].z))
			can = false;
	}
	if(can) {
		cout<<"1"<<endl;
		cout<<gg[n-1].pos;
	}
	else{
		cout<<"0"<<endl;
	}
	return 0;
}
