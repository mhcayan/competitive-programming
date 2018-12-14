#include<stdio.h>
int main()
{
	long c,t,n,sum,w;
	scanf("%ld",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%ld",&n);
		sum=0;
		while(n--)
		{
			scanf("%ld",&w);
			if(w>0)
				sum+=w;
		}
		printf("Case %ld: %ld\n",t,sum);
	}
	return 0;
}