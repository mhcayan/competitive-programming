#include<stdio.h>
int main()
{
	long n,m,sum,c,t,d;
	scanf("%ld",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%ld",&n);
		m=n;
		while(1)
		{
			sum=0;
			while(m)
			{
				d=m%10;
				sum+=d*d;
				m=m/10;
			}
			if(sum==1 || sum==4)
				break;
			m=sum;
		}
		if(sum==1)
			printf("Case #%ld: %ld is a Happy number.\n",t,n);
		else
			printf("Case #%ld: %ld is an Unhappy number.\n",t,n);
	}
	return 0;
}
			