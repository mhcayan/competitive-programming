#include<stdio.h>
#include<math.h>
#include<string.h>
#define PI 3.141592653589
int main()
{
	double dis,angle,r;
	char str[100];
	while(scanf("%lf %lf %s",&dis,&angle,str)==3)
	{
		r=dis+6440;
		if(angle==180)
			printf("%.6lf %.6lf\n",PI*r,2*r);
		else
		{
			if(angle>180)
				angle=360-angle;
		    if(!strcmp(str,"min"))
			    angle/=60;
	    	printf("%.6lf ",(angle/360)*2*PI*r);
		    angle=(180-angle)/2;
	    	angle=angle*(PI/180);
		    printf("%.6lf\n",2*r*cos(angle));
		}
	}
	return 0;
}