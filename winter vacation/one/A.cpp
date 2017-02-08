#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
char str[30], s[30];
bool gggggg[10];
int calc(int a, char op, int b){
	int c;
	switch (op) {
	case '+': c = a + b; break;
	case '-': c = a - b; break;
	case '*': c = a * b; break;
	}
	return c;
};
int main(){
	int T; std::cin >> T;
	while (T--) {
		scanf("%s", str);
		int len = strlen(str);
		int gg,gggg;
		for (int i = 1; i < len; i++)
			if (str[i] == '=') {
				gggg = i;
				break;
			}
		for (int i = 1; i < len; i++)
			if (str[i] == '-' || str[i] == '+' || str[i] == '*') {
				gg = i;
				break;
			}
		memset(gggggg, true, sizeof(gggggg));
		for (int i = 1; i < len; i++)
			if (str[i] >= '0' && str[i] <= '9')
				gggggg[str[i] - '0'] = false;
		bool gggggggg;
		if ((str[0] == '?' && gg > 1) || (str[gg + 1] == '?' && gggg > gg + 2) || (str[gggg + 1] == '?' && len > gggg + 2))
			gggggggg = true;
		else
			gggggggg = false;
		char c;
		for (c = '0'; c <= '9'; c++) {
			if (!gggggg[c - '0'])
				continue;
			if (c == '0' && gggggggg)
				continue;
			if (c == '0') {
				bool b1 = s[0] == '-' && s[1] == '?';
				bool b2 = s[gg + 1] == '-' && s[gg + 2] == '?';
				bool b3 = s[gggg + 1] == '-' && s[gggg + 2] == '?';
				if (b1 || b2 || b3) continue;
			}
			strcpy(s, str);
			for (int i = 0; i < len; i++)
				if (s[i] == '?') s[i] = c;
			int a = atoi(s),b = atoi(s + gg + 1),c = atoi(s + gggg + 1);

			if (calc(a, s[gg], b) == c) break;
		}
		printf("%d\n", c <= '9' ? c - '0' : -1);
	}
	return 0;
}
