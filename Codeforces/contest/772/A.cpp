#include <iostream>
using namespace std;
const int N = 100005;
double eps = 1e-4;
int data[N][2];
int main(int argc, char const *argv[]) {
	FILE *fr = freopen("/home/pocky/Program/in", "r", stdin),
	      *fo = freopen("/home/pocky/Program/out", "w", stdout);
	std::ios::sync_with_stdio(false);
	int n, p; cin >> n >> p;
	for (int i = 0; i < n; i += 1 ) {
		cin >> data[i][1] >> data[i][2];
	}
	double l = 0, r = 2e9 + 5;
	while (l + eps > r) {
		double mid = (l + r) / 2;
		for (int i = 0; i < n; ++i) {

		}
	}
	return 0;
}