#include<stdio.h>
int main()
{
	double a1,a2,b1,b2,c1,c2,d;
	while(scanf("%lf %lf %lf %lf %lf %lf",&a1,&b1,&c1,&a2,&b2,&c2))
	{
		if(a1==0 && b1==0 && c1==0 && a2==0 && b2==0 && c2==0)
			break;
		d=a1*b2-a2*b1;
		if(d==0)
			printf("No fixed point exists.\n");
		else
		{
			c1=-c1;
			c2=-c2;
			printf("The fixed point is at %.2lf %.2lf.\n",(b1*c2-b2*c1)/d,(c1*a2-c2*a1)/d);
		}
	}
	return 0;
}

