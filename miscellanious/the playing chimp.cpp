#include<stdio.h>
long a[100000];
void bsrch(long beg,long end,long v)
{
	long n=end+1;
	long mid;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(a[mid]==v)
			break;
		else if(v<a[mid])
			end=mid-1;
		else
			beg=mid+1;
	}
	if(beg>end)
	{
		if(end>=0)
			printf("%ld",a[end]);
		else
			printf("X");
		if(beg<n)
			printf(" %ld\n",a[beg]);
		else
			printf(" X\n");
	}
	else
	{
		if((mid-1)>=0)
			printf("%ld",a[mid-1]);
		else
			printf("X");
		if(mid+1<n)
			printf(" %ld\n",a[mid+1]);
		else
			printf(" X\n");
	}
}

int main()
{
	long n,q,i,v;
	while(scanf("%ld",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		scanf("%ld",&q);
		while(q--)
		{
			scanf("%ld",&v);
			bsrch(0,n-1,v);
		}
	}
	return 0;
}