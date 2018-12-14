#include<stdio.h>
const long inf=2000000000;
long a[30];
long lenlis(long n)
{
	long i,len,beg,end,mid,I[30];
	I[0]=-inf;
	for(i=1;i<=n;i++)
		I[i]=inf;
	len=0;
	for(i=0;i<n;i++)
	{
		beg=0;
		end=len;
	    while(beg<=end)
		{
		    mid=(beg+end)/2;
		    if(I[mid]<a[i])
				beg=mid+1;
			else
				end=mid-1;
		}
		I[beg]=a[i];
		if(beg>len)
			len=beg;
	}
	return len;
}
		
int main()
{
	long n,i,num,loc[30];
	scanf("%ld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%ld",&num);
		loc[num]=i;
	}
	while(scanf("%ld",&num)==1)
	{
		a[0]=loc[num];
		for(i=1;i<n;i++)
		{
			scanf("%ld",&num);
			a[i]=loc[num];
		}
		printf("%ld\n",lenlis(n));
	}
	return 0;
}