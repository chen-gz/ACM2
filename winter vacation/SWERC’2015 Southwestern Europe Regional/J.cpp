//Problem J Saint John Festival (凸包+判点在凸包内)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const double eps = 1e-8;
const int N = 1e4 + 10;
typedef struct Point {
	double x, y;
	Point() {
	}
	Point(double x, double y) : x(x), y(y) {
	}
} Vector;

Vector operator-(Point A, Point B){
	return Vector(A.x - B.x, A.y - B.y);
}
//点乘
double dot(Vector A, Vector B){
	return A.x * B.x + A.y * B.y;
}
//取模,norm 模!
double norm(Vector A){
	return sqrt(dot(A, A));
}
//距离
double dist(Point A, Point B){
	double dx = A.x - B.x;
	double dy = A.y - B.y;
	return sqrt(dx * dx + dy * dy);
}
//叉乘
double cross(Vector A, Vector B){
	return A.x * B.y - B.x * A.y;
}
//OA,OB的叉乘
double cross(Point A,Point O, Point B){
	return cross(A - O, B - O);
}
//取符号
int sign(double x){
	if(abs(x) < eps) return 0;
	return x > 0 ? 1 : -1;
}
int n, m;//n是总点数.m是凸包包围的点数
Point p[N], convex[N];//输入的点放在P内,输出点再convex
Point referPoint;//参考点,最左下角的点.
bool cmp1(Point p1, Point p2){
	//比较y坐标的高低,若相同比较x
	if (sign(p1.y - p2.y) != 0) return p1.y < p2.y;
	return p1.x < p2.x;
}
bool cmp2(Point p1, Point p2){
	Vector A = p1 - referPoint, B = p2 - referPoint;
	int sgn = sign(cross(A, B));
	if (sgn != 0) return sgn > 0;
	return norm(A) < norm(B);
}
void graham(){
	//求凸包
	sort(p + 1, p + n + 1, cmp1);
	referPoint = p[1];
	sort(p + 2, p + n + 1, cmp2);
	m = 0;
	convex[++m] = p[1];
	convex[++m] = p[2];
	for (int i = 3; i <= n; i++) {
		while (cross(p[i] - convex[m], convex[m] - convex[m - 1]) > 0)
			m--;
		convex[++m] = p[i];
	}
}

bool in_convex(Point P){
	if (sign(cross(P, convex[1], convex[2])) > 0) return false;
	if (sign(cross(P, convex[1], convex[m])) < 0) return false;
	int low = 2, high = m;
	while (high - low > 1) {
		int mid = low + high >> 1;
		int sgn = sign(cross(P, convex[1], convex[mid]));
		if (sgn == 0)
			return sign(dist(P, convex[1]) - dist(convex[mid], convex[1])) <= 0 ? true : false;
		if (sgn < 0)
			low = mid;
		else high = mid;
	}
	return sign(cross(P, convex[low], convex[high])) <= 0 ? true : false;
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf", &p[i].x, &p[i].y);
	graham();
	int q, ans = 0;
	scanf("%d", &q);
	while (q--) {
		Point P;
		scanf("%lf%lf", &P.x, &P.y);
		if (in_convex(P))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
