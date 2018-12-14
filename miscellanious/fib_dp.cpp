#include<stdio.h>
long fib(long);
int main()
{
	long n,res;
	scanf("%ld",&n);
	res=fib(n);
	printf("%ld\n",res);
	return 0;
}
long fib(long n)
{
	static kf[10000];
	if(kf[n]!=0)
		return kf[n];
	else
	{
		if(n==1||n==2)
			return kf[n]=1;
		else
		{
			return kf[n]=fib(n-1)+fib(n-2);
		}
	}
}
