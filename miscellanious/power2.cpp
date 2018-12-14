#include<stdio.h>
#include<time.h>
long power(long,long);
int main()
{
	clock_t s,e;
	long x,n,res;
	while(scanf("%ld %ld",&x,&n)==2)
	{
		s=clock();
		res=power(x,n);
		e=clock();
		printf("%ld^%ld=%ld\nTime=%ld\n",x,n,res,e-s);
	}
	return 0;
}
long power(long x,long n)
{
	long a;
	if(n==0)
		return 1;
	a=power(x,n/2);
	if(n%2==0)
	{
	   return a*a;
	}
	else
	{
	    return x*a*a;
	}


}
