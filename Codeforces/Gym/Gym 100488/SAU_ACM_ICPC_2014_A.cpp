//#include<iostream>
//#include<cstdio>	
//#include<algorithm>
//#include<cmath>
//#include<iomanip>
//#define pi 3.14159265359
//using namespace std;
//int main() {
//	long double a, b, c, r;
//	cin >> a >> b >> c >> r;
//	long double s = (a + b + c) / 2;
//	long double S = 0;
//	long double x = acos((a*a + b*b - c*c) / 2 / a / b) / 2;
//	S -= r*r / tan(x);
//	S += (pi - 2 * x) / 2 * r*r;
//	x = acos((a*a + c*c - b*b) / 2 / a / c) / 2;
//	S -= r*r / tan(x);
//	S += (pi - 2 * x) / 2 * r*r;
//	x = acos((b*b + c*c - a*a) / 2 / b / c) / 2;
//	S -= r*r / tan(x);
//	S += (pi - 2 * x) / 2 * r*r;
//	cout << fixed << setprecision(10) << 1 + S / sqrt(s*(s - a)*(s - b)*(s - c)) << "\n";
//	return 0;
//}