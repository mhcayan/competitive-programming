#include<stdio.h>
long l[1000005];
int main()
{
	long t,n,i,b,invalid;
	scanf("%ld",&t);
	while(t--)
	{
		invalid=0;
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
			scanf("%ld",&l[i]);
		b=1;
		for(i=1;i<n;i++)
		{
			if(l[i]>b)
			{
				invalid=1;
				break;
			}
			b=(b-l[i])*2;
		}
		if(l[n]!=b)
			invalid=1;
		if(invalid)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}


