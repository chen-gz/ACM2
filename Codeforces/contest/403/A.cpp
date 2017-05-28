#include <bits/stdc++.h>
using namespace std;
const int  MAXN = 200003;
bool a[MAXN];
int hhhh[MAXN];
int main(int argc, char const *argv[]){
	FILE *fr = freopen("/home/pocky/Program/in","r",stdin),*fo = freopen("/home/pocky/Program/out","w+",stdout);	
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i = 0;i < 2*n;i ++)
		cin>>hhhh[i];
	int ans = 0,accept = -1;
	for(int i = 0;i < 2*n;i ++) {
		if(a[hhhh[i]] == 0) {
			ans ++;
			a[hhhh[i]] = 1;
			if(ans > accept) {
				accept = ans;
			}
		}
		else 
			ans --;
	}
	cout<<accept<<'\n';
	fclose(fr);fclose(fo);
}