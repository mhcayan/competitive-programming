#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int main()
{
	long cas,t,n;
	double R,lob,r;
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%lf %ld",&R,&n);
		if(n<3)
			printf("Case %ld: %.10lf\n",t,R/2);
		else
		{
			lob=sin(PI/n);
			r=(lob/(1+lob))*R;
	        printf("Case %ld: %.10lf\n",t,r);
		}
	}
	return 0;
}