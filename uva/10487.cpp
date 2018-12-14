#include<stdio.h>
long b[500000];
int main()
{
	long a[2000],q,m,n,i,j,k,t=1,csum,diff,mdiff,flag;
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		m=n-1;
		k=0;
		for(i=0;i<m;i++)
		{
			for(j=i+1;j<n;j++)
			{
				b[k++]=a[i]+a[j];
			}
		}
		scanf("%ld",&m);
		printf("Case %ld:\n",t);
		t++;
		for(i=0;i<m;i++)
		{
			scanf("%ld",&q);
			mdiff=9999999;
			flag=0;
			for(j=0;j<k;j++)
			{
				if(b[j]==q)
				{
					flag=1;
					break;
				}
				diff=b[j]-q;
				if(diff<0)
					diff=-diff;
				if(diff<mdiff)
				{
					mdiff=diff;
					csum=b[j];
				}
			}
			if(flag)
				printf("Closest sum to %ld is %ld.\n",q,q);
			else
			    printf("Closest sum to %ld is %ld.\n",q,csum);
		}
	}
	return 0;
}



