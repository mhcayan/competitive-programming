#include<stdio.h>
#include<math.h>
#define PI 3.1415926535898
int main()
{
	long t,c;
	double r;
	scanf("%ld",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%lf",&r);
		r=r*r;
		printf("Case %ld: %.2lf\n",t,(4*r-PI*r));
	}
	return 0;
}