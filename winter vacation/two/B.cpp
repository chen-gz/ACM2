#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	std::pair<double,double> A,B,C,D,E,F;
	while(std::cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second
	      >>D.first >> D.second >> E.first >> E.second >> F.first >> F.second &&
	      ( A.first || A.second || B.first || B.second || C.first || C.second
	        ||D.first || D.second || E.first || E.second || F.first || F.second)) {
		std::pair<double,double> DE (E.first - D.first,E.second - D.second);
		std::pair<double,double> DF (F.first - D.first,F.second - D.second);
		double STriangle = 0.5 * fabs(DE.first * DF.second - DE.second * DF.first);
		std::pair<double,double> AC (C.first - A.first,C.second - A.second);
		std::pair<double,double> AB (B.first - A.first,B.second - A.second);
		double Shhh = fabs(AC.first * AB.second - AC.second * AB.first);
		double mul =  STriangle/Shhh;
		// double k = AC.second / AC.first;
		// double b = A.second - k * a.first;
		std::pair<double, double> G(AC.first*mul + A.first, AC.second * mul + A.second);
		std::pair<double, double> H(G.first + AB.first, G.second + AB.second);
		printf("%.3f %.3f %.3f %.3f", H.first, H.second, G.first, G.second);
		std::cout << std::endl;
		//std::cout << G.first << " " << G.second << " ";
		//std::cout << H.first << " " << H.second << std::endl;

	}
}
