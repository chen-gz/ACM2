#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
int main(int argc, char const *argv[]) {
	//freopen("input.txt", "r", stdin);
	string str; cin >> str;
	int cnt_left = 0;
	int cnt_right = 0;
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			cnt_left++;
		}
		else if (str[i] == ')') {
			cnt_right++;
		}
	}
	int max_left = (str.length() ) / 2;
	int cnt = 0;
	int sum_left = cnt_left;
	bool can = true;
	if ((str.length() ) % 2 != 0)
		can = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			cnt++;
		}
		else if (str[i] == ')')
			cnt--;
		else if (str[i] == '?') {
			if (sum_left < max_left) {
				str[i] = '(';
				sum_left++;
				cnt++;
			}
			else {
				str[i] = ')';
				cnt--;
			}
		}
		if (cnt < 0) {
			can = false;
			break;
		}

	}
	if (can) {
		cout << str << endl;
	}
	else
		cout << "Impossible" << endl;
	return 0;
}
