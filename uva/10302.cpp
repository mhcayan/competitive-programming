#include<stdio.h>
int main()
{
	long double n;
	while(scanf("%Lf",&n)==1)
	{
		n=(n*(n+1))/2;
		printf("%.0Lf\n",n*n);
	}
	return 0;
}
