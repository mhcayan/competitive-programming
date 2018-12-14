#include<stdio.h>
long a[100000];
long bsrch(long beg,long end,long v)
{
	if(beg>end)
		return -1;
	long mid=(beg+end)/2;
	if(a[mid]==v)
		return mid;
	else if(v>a[mid])
		return bsrch(mid+1,end,v);
	else
		return bsrch(beg,mid-1,v);
}

int main()
{
	long n,q,i,v,k;
	while(scanf("%ld %ld",&n,&q)==2)
	{
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		while(q--)
		{
			scanf("%ld",&v);
			if((k=bsrch(0,n-1,v))>=0)
				printf("%ld found at loc %ld\n",v,k);
			else
				printf("Not found\n");
		}
	}
	return 0;
}