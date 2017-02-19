#include <bits/stdc++.h>
using namespace std;
#define N 100008

int main(){
	char str[N];
	scanf("%s",str);
	char s[11] = "Bulbasr";
	int a[11] = {0};
	for(int i = 0; i < strlen(str); i++)
		for(int j = 0; j < strlen(s); j++)
			if(str[i] == s[j])
				a[j]++;
	a[1] /= 2;
	a[4] /= 2;
	int gogogo = 100003;
	for(int i = 0; i < strlen(s); i++)
		if(a[i] < gogogo)
			gogogo = a[i];
	printf("%d\n",gogogo);
	return 0;
}
