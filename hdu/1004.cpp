//hdu 1004
<<<<<<< HEAD
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int a[1000];
int main() {
	int n;
	while (~scanf("%d", &n), n) {
		memset(a, 0, sizeof(a));
		vector<string> v;
		string temp;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			int j;
			for (j = 0; j < v.size(); j++) {
				if (temp == v[j]) {
=======
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
int a[1000];
int main(){
	int n;
	while(~scanf("%d",&n),n){
		memset(a,0,sizeof(a));
		vector<string> v;
		string temp;
		for(int i=0;i<n;i++){
			cin>>temp;
			int j;
			for(j=0;j<v.size();j++){
				if(temp==v[j]){
>>>>>>> refs/remotes/origin/master
					a[j]++;
					break;
				}
			}
<<<<<<< HEAD
			if (j == v.size()) {
=======
			if(j==v.size()){
>>>>>>> refs/remotes/origin/master
				v.push_back(temp);
				a[v.size()]++;
			}
		}
<<<<<<< HEAD
		int max_num = 0;
		int max_index = 0;
		for (int i = 0; i < v.size(); i++) {
			if (a[i] > max_num) {
				max_num = a[i];
				max_index = i;
			}
		}
		cout << v[max_index] << endl;
=======
		int max_num=0;
		int max_index=0;
		for(int i=0;i<v.size();i++){
			if(a[i]>max_num){
				max_num=a[i];
				max_index=i;
			}
		}
		cout<<v[max_index]<<endl;
>>>>>>> refs/remotes/origin/master
	}
}
