#include<stdio.h>
int main()
{
	float h,u,d,f,total,day;
	while(scanf("%f %f %f %f",&h,&u,&d,&f))
	{
		if(h==0)
			break;
		f=(f/100)*u;
		total=0;
		day=0;
		while(1)
		{
			day++;
			if(u>=0)
			    total+=u;
			if(total>h)
				break;
			total-=d;
			if(total<0)
				break;
			u-=f;
		}
		if(total>h)
			printf("success on day %.0f\n",day);
		else
			printf("failure on day %.0f\n",day);
	}
	return 0;
}

