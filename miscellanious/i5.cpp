#include<stdio.h>
#include<stdlib.h>
int main()
{
	long n,i;
	n=500;
	printf("%ld\n",n);
	for(i=1;i<=n;i++)
	{
		printf("%ld ",rand()%20);
		if(i%20==0)
			printf("\n");
	}
	return 0;
}