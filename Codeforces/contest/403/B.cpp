#include <bits/stdc++.h>
const double eps = 1e-6;
using namespace std;

int n;
double tmax = -1.0;

struct frie {
	double p, v;
};

bool cmp(frie a, frie b) {
	return a.p < b.p;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	frie f[60003];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> f[i].p;
	for (int i = 0; i < n; i++)
		cin >> f[i].v;
	sort(f, f + n, cmp);
	double d = f[n - 1].p - f[0].p;
	for (int i = 0; i < n; i++) {
		double temp = d / f[i].v;
		if (temp > tmax)
			tmax = temp;
	}
	double l = 0, r = tmax;
	while (r - l > eps) {
		double tmid = (l + r) / 2.0, pll = f[0].p, prr = f[n - 1].p;
		bool isf = 0;
		while (prr - pll > eps) {
			double pmid = (pll + prr) / 2.0;
			int tem = 0;
			isf = 0;
			for (int i = 0; i < n; i++) {
				if (!(f[i].p - pmid < eps && f[i].p + tmid * f[i].v - pmid > -eps) && !(f[i].p - tmid * f[i].v - pmid < eps && f[i].p - pmid > -eps)) {
					isf = 1;
					tem = i;
					break;
				}
			}
			if (!isf)
				break;
			else {
				if (f[tem].p < pmid)
					prr = pmid;
				else
					pll = pmid;
			}
		}
		if (!isf)
			r = tmid;
		else
			l = tmid;
	}
	printf("%.7lf\n", (l + r) / 2.0);
}