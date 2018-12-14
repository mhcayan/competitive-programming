#include<stdio.h>
long step;
long gcd(long ,long);
int main()
{
	long a,b,res;
	while(scanf("%ld %ld",&a,&b)==2)
	{
		step=0;
	   res=gcd(a,b);
	   printf("gcd=%d ,step=%ld\n",res,step);
	}
	return 0;
}
long gcd(long a,long b)
{
	step++;
	if(b==0)
		return a;
	return gcd(b,a%b);
}
	

