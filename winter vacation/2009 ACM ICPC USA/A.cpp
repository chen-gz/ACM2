#include <bits/stdc++.h>
char hhh[7][7];
int main(int argc, char const *argv[]) {
	char ch;
	while(scanf("%c", &ch) && ch != '*') {
		str::pair<int,int> pos;
		for(int i=0; i<6; i++) {
			scanf("%s",hhh[i]);
			for(int j=0; j<6; j++) {
				if(hhh[i][j]==ch) {
					pos.first = i;
					pos.second = j;
					break;
				}
			}
		}
		for(int i=pos.second+1; i<6; i++) {
			if(hhh[pos.first][i]!='.') {
                //开始移动。
                char tmp =
			}

		}

	}
	return 0;
}
