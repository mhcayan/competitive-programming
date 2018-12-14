#include<stdio.h>
const long inf=2000000000;
long a[100],l[100];
void printlis(long n,long len)
{
	long i,j,top,b[100];
	i=0;
	for(j=1;j<n;j++)
	{
		if(l[j]>l[i])
			i=j;
	}
	top=len-1;
	b[top]=a[i];
	top--;
	for(j=i-1;j>=0;j--)
	{
		if(a[j]<a[i] && l[j]==l[i]-1)
		{
			b[top]=a[j];
			top--;
			i=j;
		}
	}
	for(i=0;i<len;i++)
		printf("%ld\n",b[i]);
	printf("\n");
}
long lislen(long n)
{
	long beg,end,mid,lislen,i,I[100];
	lislen=0;
	I[0]=-inf;
	for(i=1;i<=n;i++)
		I[i]=inf;
	for(i=0;i<n;i++)
	{
		beg=0;
	    end=lislen;
		while(beg<=end)
		{
			mid=(beg+end)/2;
			if(I[mid]<a[i])
				beg=mid+1;
			else
				end=mid-1;
		}
		I[beg]=a[i];
		l[i]=beg;
		if(beg>lislen)
			lislen=beg;
	}
	return lislen;
}
int main()
{
	long n,i,cas,t,len;
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		len=lislen(n);
		printf("%ld\n",len);
		printlis(n,len);
	}
	return 0;
}
