#include<stdio.h>
#include<math.h>
#define pi 3.141592653589793
int main()
{
	long t=1,n;
	double area,a,r;
	while(scanf("%ld %lf",&n,&area) && n>2)
	{
		a=sqrt(area/(n*tan(pi/n)));
		r=a/cos(pi/n);
		printf("Case %ld: %.5lf %.5lf\n",t++,pi*r*r-area,area-pi*a*a);
	}
	return 0;
}
