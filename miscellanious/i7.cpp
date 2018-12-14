#include<stdio.h>
#include<stdlib.h>
int main()
{
	long n=70;
	printf("%ld\n",n);
	for(long i=0;i<=n;i++)
	{
		printf("%ld ",rand()%100);
		if((i+1)%15==0)
			printf("\n");
	}
	return 0;
}