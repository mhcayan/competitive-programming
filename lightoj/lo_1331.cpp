#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int main()
{
	long cas,t;
	double r1,r2,r3,a,b,c,A,B,C,area,s;
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%lf %lf %lf",&r1,&r2,&r3);
		a=r1+r2;
		b=r2+r3;
		c=r1+r3;
		s=(double)(a+b+c)/2;
		area=sqrt(s*(s-a)*(s-b)*(s-c));
		A=acos((b*b+c*c-a*a)/(2*b*c))*(180/PI);
		B=acos((c*c+a*a-b*b)/(2*c*a))*(180/PI);
		C=acos((a*a+b*b-c*c)/(2*a*b))*(180/PI);
		area-=(A/360)*PI*r3*r3;
		area-=(B/360)*PI*r1*r1;
		area-=(C/360)*PI*r2*r2;
		printf("Case %ld: %.10lf\n",t,area);
	}
	return 0;
}
