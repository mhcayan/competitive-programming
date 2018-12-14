#include<stdio.h>
#include<math.h>
int main()
{
	long cas,t;
    long long n,e;
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%lld",&n);
		if(n%2)
			printf("Case %ld: Impossible\n",t);
		else
		{
			e=0;
			while(n%2==0)
			{
				n=n/2;
				e++;
			}
			printf("Case %ld: %lld %.0lf\n",t,n,pow(2,e));
		}
	}
	return 0;
}
