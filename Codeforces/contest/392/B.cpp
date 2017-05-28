#include <bits/stdc++.h>
using namespace std;
#define maxn 1000
int color[maxn];
int main(int argc, char const *argv[]) {
	string s; cin>>s;
	int cnt = 0;
	bool have[5]={0,0,0,0,0};
	int ans[5]={0,0,0,0,0};
	for(auto i =0; i<s.length() && cnt <4; i++) {
		if(s[i]=='R' && have[1] == false) {
			color[i] = 1;
			int mod = i %4;
			for(unsigned int j=mod; j<s.length(); j+=4) {
				color[j] = 1;
			}
			cnt++;
			have[1] = true;
		}
		else if(s[i]=='B' && have[2]==false) {
			color[i] = 2;
			int mod = i %4;
			for(unsigned int j=mod; j<s.length(); j+=4) {
				color[j] = 2;
			}
			cnt++;
			have[2]=true;
		}
		else if(s[i]=='Y' && !have[3]) {
			color[i] = 3;
			int mod = i %4;
			for(unsigned int j=mod; j<s.length(); j+=4) {
				color[j] = 3;
			}
			cnt++;
			have[3] =true;
		}
		else if(s[i]=='G' && !have[4]) {
			color[i] = 4;
			int mod = i %4;
			for(unsigned int j=mod; j<s.length(); j+=4) {
				color[j] = 4;
			}
			cnt++;
			have[4] = true;
		}
	}

	for(int i =0; i<s.length(); i++) {
		if(s[i]=='!') {
			ans[color[i]]++;
		}
	}
	for(int i =1; i<5; i++) {
		cout<<ans[i]<< " ";
	}
	std::cout << '\n';
	return 0;
}
