#include<stdio.h>
int main()
{
	long long t=1,n,i,j,max,mul,a[100];
	while(scanf("%lld",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		max=0;
		for(i=0;i<n;i++)
		{
			if(a[i]==0)
				continue;
			mul=a[i];
			if(mul>max)
				max=mul;
			for(j=i+1;j<n;j++)
			{
				mul*=a[j];
				if(mul==0)
					break;
				if(mul>max)
					max=mul;
			}
		}
		printf("Case #%lld: The maximum product is %lld.\n\n",t++,max);
	}
	return 0;
}
