//#include<iostream>
//#include<vector>
//#include<string>
//#include<cmath>
//using namespace std;
////w=0 Q 后, B 象 R 车
//#define INF  0xfffffffff
//struct node {
//	long long  x, y, w;
//	node(long long x, long long  y, long long  w) {
//		this->x = x;
//		this->y = y;
//		this->w = w;
//	}
//};
//int main() {
//	long long  n; cin >> n;
//	long long x0, y0; cin >> x0 >> y0;
//	vector<node> v;
//	v.push_back(node(-INF, INF, 2));
//	v.push_back(node(INF, INF, 2));
//	v.push_back(node(x0, -INF, 2));
//	v.push_back(node(x0, INF, 2));
//	v.push_back(node(+INF, -INF, 3));
//	v.push_back(node(+INF, -INF, 3));
//	v.push_back(node(-INF, +INF, 3));
//	v.push_back(node(-INF, -INF, 3));
//	for (long long i = 0; i < n; i++) {
//		char a; cin >> a;
//		long long  tx, ty; cin >> tx >> ty;
//		long long  w;
//		switch (a) {
//		case 'Q': w = 1; break;
//		case 'B': w = 2; break;
//		case 'R': w = 3; break;
//		}
//		//判断处于哪个方位;
//		if (tx == x0 || ty == y0 || abs(tx - x0) == abs(ty - y0)) {
//			if (ty == y0) {
//				if (tx <= x0 && tx >= v[0].x) {
//					v[0].x = tx;
//					v[0].y = ty;
//					v[0].w = w;
//				}
//				else if (tx >= x0 && tx <= v[1].x) {
//					v[1].x = tx;
//					v[1].y = ty;
//					v[1].w = w;
//				}
//			}
//			else if (tx == x0) {
//				if (ty <= y0 && ty >= v[2].y) {
//					v[2].x = tx;
//					v[2].y = ty;
//					v[2].w = w;
//				}
//				else if (ty >= y0 && ty <= v[3].y) {
//					v[3].x = tx;
//					v[3].y = ty;
//					v[3].w = w;
//				}
//			}
//			else {
//				if (tx >= x0 && ty >= y0 && tx <= v[4].x) {
//					v[4].x = tx;
//					v[4].y = ty;
//					v[4].w = w;
//				}
//				else if (tx >= x0 && ty <= y0 && tx <= v[5].x) {
//					v[5].x = tx;
//					v[5].y = ty;
//					v[5].w = w;
//				}
//				else if (tx <= x0 && ty >= y0 && tx >= v[6].x) {
//					v[6].x = tx;
//					v[6].y = ty;
//					v[6].w = w;
//				}
//				else if (tx <= x0 && ty <= y0 && tx >= v[7].x) {
//					v[7].x = tx;
//					v[7].y = ty;
//					v[7].w = w;
//				}
//			}
//		}
//	}
//	bool flag = false;
//	for (int i = 0; i < 4; i++) {
//		if (v[i].w == 1 || v[i].w == 3) {
//			flag = true;
//		}
//	}
//	for (int i = 4; i < 8; i++) {
//		if (v[i].w == 1 || v[i].w == 2) {
//			flag = true;
//		}
//	}
//	if (flag) {
//		cout << "YES" << endl;
//	}
//	else {
//		cout << "NO" << endl;
//	}
//	return 0;
//}