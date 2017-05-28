#include <bits/stdc++.h>
using namespace std;
static int cows=0,bulls = 0;
void hhh(int &i,int &j,int &k,int &l,int &q){
	for(q=1; q<10; q++) {
		fflush(stdout);
		cout<<i<<j<<k<<l<<endl;
		int bt,ct; cin>>bt>>ct;
		if(bt != bulls) {
			if(bt<bulls) {
				q = 0;
				bulls = bt+1;
			}
			else
				bulls = bt;
			break;
		}
	}
}
int main(int argc, char const *argv[]) {
	int i,j,k,l;
	i=j=k=l=0;
	fflush(stdout);
	cout<<i<<j<<k<<l<<endl;
	cin>>bulls>>cows;
	hhh(i,j,k,l,i);
	hhh(i,j,k,l,j);
	hhh(i,j,k,l,k);
	hhh(i,j,k,l,l);
	cout<<i<<j<<k<<l<<endl;
	return 0;
}
