#include<stdio.h>
#include<time.h>
int main()
{
	clock_t e,s;
	long x,n,res=1,i;
	scanf("%ld %ld",&x,&n);
	s=clock();
	for(i=1;i<=n;i++)
	{
		res*=x;
	}
	e=clock();
	printf("%ld time=%ld\n",res,e-s);
	return 0;
}
