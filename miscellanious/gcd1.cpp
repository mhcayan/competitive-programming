#include<stdio.h>
int main()
{
	int a,b,rem=1,t;

	while(scanf("%d %d",&a,&b)==2)
	{
/*	if(a>b)
	{
		t=a;
		a=b;
		b=t;
	}*/
	while(1)
	{
		rem=b%a;
		if(rem==0)
			break;
		b=a;
		a=rem;
		
	}
	printf("gcd=%d\n",a);
	}
	return 0;
}

