#include<stdio.h>
int main()
{
	int cas,tc=1,n,c,b,e,mid,i,sum,cnt,a[1003];
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d %d",&n,&c);
		b=0;
		e=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			e+=a[i];
			if(a[i]>b)
			{
				b=a[i];
			}
		}
		while(b<=e)
		{
			mid=(b+e)/2;
			i=0; cnt=1; sum=0;
			while(i<n)
			{
				if(sum+a[i]<=mid)
				{
					sum+=a[i];
				}
				else
				{
					sum=a[i];
					cnt++;
					if(cnt>c)
				    {
					   break;
				    }
				}
				i++;
			}
			if(cnt<=c)
			{
				e=mid-1;
			}
			else
			{
				b=mid+1;
			}
		}
		printf("Case %d: %d\n",tc++,b);
	}
	return 0;
}
