#include<stdio.h>
int main()
{
	long c,t,m,n;
	scanf("%ld",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%ld %ld",&n,&m);
		printf("Case %ld: %ld\n",t,(n/2)*m);
	}
	return 0;
}
