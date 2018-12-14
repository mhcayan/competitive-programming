//compile in dev
#include<stdio.h>
int main()
{
	long long a[51],n,i;
	a[1]=1;
	a[2]=2;
	for(i=3;i<=50;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	while(scanf("%lld",&n) && n)
	{
		printf("%lld\n",a[n]);
	}
	return 0;
}
