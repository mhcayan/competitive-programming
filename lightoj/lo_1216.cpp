#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int main()
{
	int cas,t;
	double r1,r2,r3,h,p,x;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%lf %lf %lf %lf",&r1,&r2,&h,&p);
		x=r2*h/(r1-r2);
		r3=(p+x)*r2/x;
		printf("Case %d: %.9lf\n",t,(PI*r3*r3*(p+x)-PI*r2*r2*x)/3);
	}
	return 0;
}
