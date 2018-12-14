#include<stdio.h>
const long inf=2000000000;
long a[200000],l[200000],b[200000];
void printlis(long n,long len)
{
	long i,j,top;
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
			i=j;
			top--;
			if(top<0)
				break;
		}
	}
	for(i=0;i<len;i++)
		printf("%ld\n",b[i]);
}

long lenlis(long n)
{
	long beg,end,mid,i,len,I[200000];
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
		l[i]=beg;
		if(beg>len)
			len=beg;
	}
	return len;
}

int main()
{
	long n=-1,len;
	while(scanf("%ld",&a[++n])==1);
	len=lenlis(n);
	printf("%ld\n-\n",len);
	printlis(n,len);
	return 0;
}
