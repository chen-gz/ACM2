#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	FILE *fr = freopen("/home/wendell/Program/in", "r", stdin),
	      *fo = freopen("/home/wendell/Program/out", "w", stdout);
	string s1, s2, s3;
	cin >> s1 >> s2;
	int len1 = s1.length();
	bool flag = true;
	for (int i = 0; i < len1; ++i)
	{
		if (s1[i] < s2[i])
			flag = false;
		else if (s1[i] == s2[i])
			s3.push_back(s1[i]);
		else
			s3.push_back(s2[i]);
	}
	if (flag)
		cout << s3 << endl;
	else
		cout << "-1" << endl;
	return 0;
}