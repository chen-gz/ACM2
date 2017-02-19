#include <iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
struct City {
	int index;
	int population;
	int position;
	int left_biger;
	int right_biger;
	int father;
	City() {
		left_biger = -1;
		right_biger = -1;
	}
};
bool cmp2(City a, City b) {
	return a.index < b.index;
}
bool cmp(City a, City b) {
	return a.position < b.position;
};
City city[200005];
int main(int argc, char const *argv[]) {
	freopen("input.txt", "r", stdin);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &city[i].position, &city[i].population);
		city[i].index = i;
	}
	sort(city, city + n, cmp);
	stack<int> 	st;//单调递减栈;
	for (int i = 0; i < n; i++) {
		if (!st.empty()) {
			while (!st.empty() && city[st.top()].population < city[i].population) {
				city[st.top()].right_biger = i;
				st.pop();
			}
		}
		//if (!st.empty()) {
		//	city[i].left_biger = city[st.top()].index;// = st.top();
		//}
		if (st.empty()) {
			st.push(i);
			city[i].left_biger = -1;
		}
		else if (!st.empty()) {
			city[i].left_biger = st.top();
			st.push(i);
		}

	}
	while (!st.empty()) {
		city[st.top()].right_biger = -1;
		st.pop();
	}
	for (int i = 0; i < n; i++) {
		if (city[i].left_biger == -1 && city[i].right_biger == -1) {
			city[i].father = -1;
		}
		else if (city[i].left_biger == -1) {
			city[i].father = city[city[i].right_biger].index + 1;

		}
		else if (city[i].right_biger == -1) {
			city[i].father = city[city[i].left_biger].index + 1;
		}
		else {
			if ((city[city[i].right_biger].position - city[i].position) > (city[i].position - city[city[i].left_biger].position)) {
				city[i].father = city[city[i].left_biger].index + 1;
			}
			else if ((city[city[i].right_biger].position - city[i].position) == (city[i].position - city[city[i].left_biger].position) ) {
				if (city[city[i].right_biger].population > city[city[i].left_biger].population) {
					city[i].father = city[city[i].right_biger].index + 1;
				}
				else {
					city[i].father = city[city[i].left_biger].index + 1;
				}
			}
			else
				city[i].father = city[city[i].right_biger].index + 1;
		}
	}
	sort(city, city + n, cmp2);
	for (int i = 0; i < n; i++) {
		printf("%d ", city[i].father);
	}
	printf("\n");
	return 0;
}