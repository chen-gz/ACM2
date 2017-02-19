//
//#include <iostream>
//#include <stdio.h>
//#include <string.h>
//#include <algorithm>
//#include <queue>
//#include <map>
//#include <vector>
//#include <set>
//#include <string>
//#include <math.h>
//
//using namespace std;
//
//const double eps = 1e-8;
//int sgn(double x)
//{
//	if (fabs(x) < eps)return 0;
//	if (x < 0) return -1;
//	return 1;
//}
//struct Point
//{
//	double x, y;
//	Point() {}
//	Point(double _x, double _y)
//	{
//		x = _x; y = _y;
//	}
//	Point operator -(const Point &b)const
//	{
//		return Point(x - b.x, y - b.y);
//	}
//	double operator ^(const Point &b)const
//	{
//		return x*b.y - y*b.x;
//	}
//	double operator *(const Point &b)const
//	{
//		return x*b.x + y*b.y;
//	}
//};
//struct Line
//{
//	Point s, e;
//	Line() {}
//	Line(Point _s, Point _e)
//	{
//		s = _s; e = _e;
//	}
//};
//double xmult(Point p0, Point p1, Point p2) //p0p1 X p0p2
//{
//	return (p1 - p0) ^ (p2 - p0);
//}
//bool Seg_inter_line(Line l1, Line l2) //判断直线l1和线段l2是否相交
//{
//	return sgn(xmult(l2.s, l1.s, l1.e))*sgn(xmult(l2.e, l1.s, l1.e)) <= 0;
//}
//double dist(Point a, Point b)
//{
//	return sqrt((b - a)*(b - a));
//}
//const int MAXN = 110;
//Line line[MAXN];
//bool check(Line l1, int n)
//{
//	if (sgn(dist(l1.s, l1.e)) == 0)return false;
//	for (int i = 0; i < n; i++)
//		if (Seg_inter_line(l1, line[i]) == false)
//			return false;
//	return true;
//}
//int main()
//{
//	//freopen("in.txt","r",stdin);
//	//freopen("out.txt","w",stdout);
//	int n;
//	int T;
//	scanf("%d", &T);
//	while (T--)
//	{
//		scanf("%d", &n);
//		double x1, y1, x2, y2;
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
//			line[i] = Line(Point(x1, y1), Point(x2, y2));
//		}
//		bool flag = false;
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				if (check(Line(line[i].s, line[j].s), n) || check(Line(line[i].s, line[j].e), n)
//					|| check(Line(line[i].e, line[j].s), n) || check(Line(line[i].e, line[j].e), n))
//				{
//					flag = true;
//					break;
//				}
//		if (flag)
//			printf("Yes!\n");
//		else printf("No!\n");
//	}
//	return 0;
//}