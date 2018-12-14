#include<stdio.h>
const long inf=2000000000;
int main()
{
	long n,x1,x2,y1,y2,maxx,minx,maxy,miny;
	while(scanf("%ld",&n)==1)
	{
		maxx=maxy=-inf;
		minx=miny=inf;
		while(n--)
		{
			scanf("%ld %ld %ld %ld",&x1,&x2,&y1,&y2);
			{
				if(x1>maxx)
					maxx=x1;
				if(x2<minx)
					minx=x2;
				if(y1>maxy)
					maxy=y1;
				if(y2<miny)
					miny=y2;
			}
			
		}
		if(minx>maxx && miny>maxy )
				printf("%ld\n",(minx-maxx)*(miny-maxy));
		else 
			printf("0\n");
	}
	return 0;
}