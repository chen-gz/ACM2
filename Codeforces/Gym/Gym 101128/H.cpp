#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;

ull num[1000005];
int noo;

ull gg(int n,int i, int j)
{
	int m=i+j;
	n /= m;
	ull tmp=1;
	tmp=(tmp<<i)-1;
	ull sum=tmp;
	while(n--)
	{
		sum<<=m;
		sum+=tmp;
	}
	return sum;
}

ull f(int n, int i, int j)
{
	int m=i+j;
	n /= m;
	ull tmp=1;
	tmp=(tmp<<i)-1;
	tmp<<=j;
	ull sum = tmp;
	n--;
	while(n--)
	{
		sum<<=m;
		sum+=tmp;
	}
	return sum;
}

int fuck(ull tmp)
{
	if(tmp>=num[noo-1]) return noo;
	int i=0;
	while(num[i]<=tmp) i++;
	return i;
}

int main(){
	ull tmp=1;
	for(int i=1; i<=63; i++) {
		for(int j=1; j<i; j++) {
			for(int k=1; k<i; k++) {
				if(i%(j+k)==0) {
					num[noo++]=f(i,j,k);
				}
				if((i-j)%(j+k)==0) {
					num[noo++]=gg(i,j,k);
				}
			}
		}
		num[noo++]=(tmp<<i)-1;
	}
	sort(num, num+noo);
	ull m, n;
	cin >> m >> n;
	if(m==0) m=1;
	cout<<fuck(n)-fuck(m-1)<<endl;
	return 0;
}
