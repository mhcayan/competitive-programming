#include<stdio.h>
int main()
{
	double n,i,max,a,b,loc,l,tmax,min;
	while(scanf("%lf",&n) && n)
	{
		tmax=-1;
		for(i=1;i<=n;i++)
		{
			scanf("%lf %lf",&a,&b);
			if(a>b)
			{
				max=a;min=b;
			}
			else
			{
				max=b;min=a;
			}
			if(min*4<=max)
				l=min;
			else
				l=max/4;
			if(min/2>l)
				l=min/2;
			if(l>tmax)
			{
				tmax=l;
				loc=i;
			}
		}
		printf("%.0lf\n",loc);
	}
	return 0;
}