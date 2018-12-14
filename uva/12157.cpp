#include<stdio.h>
#include<math.h>
int main()
{
	long mc,jc,c,t,d,i,n;
	scanf("%ld",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%ld",&n);
		mc=0;
		jc=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&d);
			if(d<30)
				mc+=10;
			else
				mc+=10+10*ceil((double)(d-29)/30);
			if(d<60)
				jc+=15;
			else
				jc+=15+15*ceil((double)(d-59)/60);
		}
		printf("Case %ld: ",t);
		if(mc==jc)
			printf("Mile Juice %ld\n",mc);
		else if(mc<jc)
			printf("Mile %ld\n",mc);
		else
			printf("Juice %ld\n",jc);
	}
	return 0;
}
