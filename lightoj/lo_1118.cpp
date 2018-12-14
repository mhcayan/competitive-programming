#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
inline double sqr(double a)
{
	return a*a;
}
int main()
{
	int cas,t;
	double x0,x1,y0,y1,r0,r1,A,B,d;
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%lf %lf %lf %lf %lf %lf",&x0,&y0,&r0,&x1,&y1,&r1);
		d=sqrt(sqr(x1-x0)+sqr(y1-y0));
		A=2*acos((r0*r0+d*d-r1*r1)/(2*r0*d));
		B=2*acos((r1*r1+d*d-r0*r0)/(2*r1*d));
		printf("Case %d: %lf\n",t,(r0*r0*(A-sin(A))+r1*r1*(B-sin(B)))/2);
	}
	return 0;
}