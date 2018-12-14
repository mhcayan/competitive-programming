#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,s,area;
	while(scanf("%f %f %f",&a,&b,&c)==3)
	{
		s=(a+b+c)/2;
		area=s*(s-a)*(s-b)*(s-c);
		if(area<=0)
			printf("-1\n");
		else
		{
			area=1.33333333*sqrt(area);
	    	printf("%.3f\n",area);
		}
	}
	return 0;
}
