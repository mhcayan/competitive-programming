#include<stdio.h>
long gcd(long a,long b)
{
	if(b%a==0)
		return a;
	return gcd(b%a,a);
}

int main()
{
	long long  x,y,g,l;
	while(scanf("%lld %lld",&x,&y)==2)
	{
		g=gcd(x,y);
		l=(x*y)/g;
		printf("%lld\n",l/x);
	}
	return 0;
}