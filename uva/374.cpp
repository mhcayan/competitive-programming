#include<stdio.h>
long bigmod(long b,long p,long m);
long squre(long a);
int main()
{
	long b,p,m;
	while((scanf("%ld %ld %ld",&b,&p,&m))==3)
		printf("%ld\n",bigmod(b,p,m));
	return 0;
}
long bigmod(long b,long p,long m)
{
	if(m==1||b==0)
		return 0;
	else if(p==0)
		return 1;
	else if(p%2)
		return (b%m * bigmod(b,p-1,m))%m;
	else
		return squre(bigmod(b,p/2,m))%m;
}
long squre(long a)
{
	return a*a;
}
