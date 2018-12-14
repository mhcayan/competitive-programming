#include<stdio.h>
long square(long n)
{
	return n*n;
}
long bigmod(long b,long p,long m)
{
	if(p==0)
		return 1;
	else if(p%2==0)
		return square(bigmod(b,p/2,m))%m;
	else
		return (b%m*bigmod(b,p-1,m))%m;
}
int main()
{
	long c,t,n,res;
	scanf("%ld",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%ld",&n);
		res=(bigmod(2,n-1,1000000007)*n%1000000007)%1000000007;
		printf("Case #%ld: %ld\n",t,res);
	}
	return 0;
}
