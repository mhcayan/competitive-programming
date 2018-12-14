#include<stdio.h>
#include<math.h>
#define PI acos(-1)
#define EPS 1e-1
int main()
{
	printf("%lf\n",PI);
	double l,n,c,L,r,beg,end,mid;
	while(scanf("%lf %lf %lf",&l,&n,&c))
	{
		if(l<0 && n<0 && c<0 )
			break;
		L=(1+n*c)*l;
		beg=0.0000001;
		end=PI;
		while(beg<=end)
		{
			mid=(beg+end)/2;
			r=L/mid;
			if(fabs(2*r*sin(mid/2))-l<EPS)
				break;
		}
		printf("%.3lf\n",r-r*cos(mid/2));
	}
	return 0;
}
