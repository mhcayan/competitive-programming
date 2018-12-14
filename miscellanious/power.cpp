#include<stdio.h>
long power(long,long);
int main()
{
	long x,n,res;
	while(scanf("%ld %ld",&x,&n)==2)
	{
		res=power(x,n);
		printf("%ld^%ld=%ld\n",x,n,res);
	}
	return 0;
}
	
long power(long x,long n)
{
	if(n==0)
		return 1;
	return x*power(x,n-1);

}
