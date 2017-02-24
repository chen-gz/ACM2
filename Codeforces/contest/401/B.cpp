#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(char a, char b) {
	return a > b;
}
int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	//FILE *fl = freopen("input.txt", "r", stdin);
	int n; cin >> n;
	char str1[2000], str2[2000]; cin >> str1 >> str2;

	sort(str1, str1 + n, cmp);
	sort(str2, str2 + n, cmp);
	long long min = 0;
	long long max = 0;
	int temp = 0;
	for (int i = 0; i < n && temp < n; i++) {
		if (str2[temp] - str1[i] > 0) {
			max++;
			temp++;
		}
	}
	temp = 0;
	for (int i = 0; i < n; i++) {
		if (str2[temp] - str1[i] >= 0) {
			min++;
			temp++;
		}
	}
	min = n - min;
	cout << min << "\n" << max << "\n";
	//fclose(fl);
	return 0;
}