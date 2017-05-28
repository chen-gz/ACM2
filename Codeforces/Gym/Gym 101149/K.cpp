#include <cstdio>
double a,b,x,y,xx,yy;
int main()
{
	a=0.916297857297023;
	scanf("%lf %lf %lf %lf",&x,&y,&xx,&yy);
	b=sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
	printf("%.10lf",b*b*a);
	return 0;
}
