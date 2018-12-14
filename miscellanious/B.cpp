#include<stdio.h>
long fact(long n)
{
    if(n==0)
    return 1;
    long i;
  long    f=1;
    for(i=1;i<=n;i++)
    f=f*i;
    return f;
}
int main()
{
	long double n,sum;
	long i;
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n1 2\n2 2.5\n");
	for(n=3;n<10;n++)
	{
		sum=0;
		for(i=0;i<=n;i++)
		{
			sum+=(long double)1/fact(i);
		}
		printf("%.0Lf %.9Lf\n",n,sum);
	}
	return 0;
}