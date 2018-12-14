#include<stdio.h>
long a[100000];
void bsrch(long beg,long end,long v)
{
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
		printf("not found beg=%ld end=%ld\n",beg,end);
	else
		printf("%ld found at %ld\n",v,mid);
}


int main()
{
	long n,q,i,v;
	while(scanf("%ld %ld",&n,&q)==2)
	{
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		while(q--)
		{
			scanf("%ld",&v);
			bsrch(0,n-1,v);
		}
	}
	return 0;
}