#include<stdio.h>
int main()
{
	long t,c,n,p=10000007;
	scanf("%ld",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%ld",&n);
		printf("Case #%ld:%ld\n",t,((n%p)*((n+1)%p)*((2*n+2)%p))%p);
	}
	return 0;
}
