//compile in dev
#include<stdio.h>
int main()
{
	long c,t,n;
	long long a[51];
	a[1]=2;
	a[2]=3;
	for(c=3;c<=50;c++)
		a[c]=a[c-1]+a[c-2];
	scanf("%ld",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%ld",&n);
		printf("Scenario #%ld:\n%lld\n\n",t,a[n]);
	}
	return 0;
}
