#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	//freopen("input.txt", "r", stdin);
	double x1, y1, x2, y2; scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	double vx1, vy1, vx2, vy2;
	scanf("%lf%lf%lf%lf", &vx1, &vy1, &vx2, &vy2);
	vx2 -= vx1; vy2 -= vy1;
	double d1 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	double d2 = (x2 + 0.0000001 * vx2 - x1) * (x2 + 0.0000001 * vx2 - x1) + (y2 + 0.0000001 * vy2 - y1) * (y2 + 0.0000001 * vy2 - y1);
	double ans  = fabs(vy2 * x1 - vx2 * y1 - x2 * vy2 + y2 * vx2) / sqrt(vy2 * vy2 + vx2 * vx2);
	if (d2 < d1) printf("%.10lf\n", ans);
	else printf("%.10lf\n", sqrt(d1));
	return 0;
}