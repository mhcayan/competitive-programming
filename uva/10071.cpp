#include<stdio.h>
int main()
{
	long t,v;
	while(scanf("%ld %ld",&t,&v)==2)
	{
		printf("%ld\n",2*v*t);
	}
	return 0;
}