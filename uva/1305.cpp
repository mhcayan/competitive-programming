#include<stdio.h>
#include<math.h>
int main()
{
	long cas,t,ax,ay,bx,by,cx,cy,area,dx,dy;
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%ld %ld %ld %ld %ld %ld",&ax,&ay,&bx,&by,&cx,&cy);
		dx=cx-(bx-ax);
		dy=ay+cy-by;
		area=abs((dx-ax)*(by-ay)-(bx-ax)*(dy-ay));
		printf("Case %ld: %ld %ld %ld\n",t,dx,dy,area);
	}
	return 0;
}