#include<stdio.h>
int main()
{
	long n=600;
	printf("%ld\n",n);
	for(long i=0;i<=n;i++)
	{
		printf("%ld ",i+1);
		if((i+1)%15==0)
			printf("\n");
	}
	return 0;
}