#include <bits/stdc++.h>

using namespace std;
string a, b;
set<string> s;

void generate(int i, int j, string res){
	if (i == a.length() && j == b.length()) // no more letters left, add the string to the set of possible strings.
		s.insert(res);
	else{
		if (i<a.length())
			generate(i + 1, j, res + a[i]); // add a letter from string 'a'
		if (j<b.length())
			generate(i, j + 1, res + b[j]); // add a letter from string 'b'
	}
}

int main(){
	int T;
	cin >> T;
	string zero;
	while (T--) {
		cin >> a >> b;
		s.clear();
		generate(0, 0, zero);
		set<string>::iterator iter;
		for (iter = s.begin(); iter != s.end(); iter++) {
			cout << *iter << endl;
		}
		cout << endl;
	}
	return 0;
}
