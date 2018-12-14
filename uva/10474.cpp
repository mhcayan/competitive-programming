#include<stdio.h>
int main()
{
	int a[10000],b[10000],c[10000],m[10000],i,j,max,q,n,t=1;
	while(scanf("%d %d",&n,&q))
	{
		if(n==0 && q==0)
			break;
		max=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>max)
				max=a[i];
		}
		for(i=0;i<q;i++)
			scanf("%d",&m[i]);
		for(i=0;i<=max;i++)
			c[i]=0;
		for(i=1;i<=n;i++)
			c[a[i]]++;
		for(i=1;i<=max;i++)
			c[i]+=c[i-1];
		for(i=n;i>0;i--)
		{
			b[c[a[i]]]=a[i];
			c[a[i]]--;
		}
		printf("CASE# %d:\n",t);
		for(j=0;j<q;j++)
		{
			for(i=1;i<=n;i++)
			{
				if(b[i]==m[j])
					break;
			}
			if(i>n)
				printf("%d not found\n",m[j]);
			else
				printf("%d found at %d\n",m[j],i);
		}
		t++;
	}
	return 0;
}
