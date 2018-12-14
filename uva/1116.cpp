#include<stdio.h>
int main()
{
	long cas,t,n,e;
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%ld",&n);
		if(n%2)
			printf("Case %ld: Impossible\n",t);
		else
		{
			e=1;
			while(n%2==0)
			{
				n=n/2;
				e*=2;
			}
			printf("Case %ld: %ld %ld\n",t,n,e);
		}
	}
	return 0;
}
