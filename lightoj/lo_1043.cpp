#include<stdio.h>
#include<math.h>
int main()
{
	int cas,t;
	double c,b,a,r,ar1,ar2,s;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%lf %lf %lf %lf",&c,&b,&a,&r);
		s=(a+b+c)/2;
		ar2=sqrt(s*(s-a)*(s-b)*(s-c));
		ar1=(ar2*r)/(r+1);
		printf("Case %d: %.10lf\n",t,sqrt(ar1/ar2)*c);
	}
	return 0;
}

