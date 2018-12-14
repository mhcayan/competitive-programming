#include<stdio.h>
int main()
{
	long long a,m,n,t,c,sum,d;
	scanf("%lld",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%lld %lld",&n,&m);
		sum=(n/2)*(n+1);
		if(m%2==0)
			a=(m/2)*(m+1);
		else
			a=m*((m+1)/2);
		d=m*m*2;
		n=n/(2*m);
		sum-=n*(2*a+(n-1)*d);
		printf("Case %lld: %lld\n",t,sum);
	}
	return 0;
}
