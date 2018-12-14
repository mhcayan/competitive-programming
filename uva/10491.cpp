#include<stdio.h>
int main()
{
	double cow,car,t,s,show,m;
	while(scanf("%lf %lf %lf",&cow,&car,&show)==3)
	{
		t=cow+car;
		m=t-show-1;
		s=cow*(car/m)+car*((car-1)/m);
		printf("%.5lf\n",s/t);
	}
	return 0;
}
