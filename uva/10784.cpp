#include<stdio.h>
#include<math.h>
int main()
{
	long long n,t=1;
	double d;
	while(scanf("%lf",&d) && d)
	{
		n=ceil((3+sqrt(9+4*2*d))/2);
		printf("Case %lld: %lld\n",t++,n);
	}
	return 0;
}

		
