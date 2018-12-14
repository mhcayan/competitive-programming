#include<stdio.h>
#include<stdlib.h>
const long inf=2000000000;
long a[100000],l[100000];
long lenlis(long n)
{
	long I[100000],i,len,beg,end,mid;
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
void printlis(long n,long len)
{
	long b[100000],top,i,j;
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
int main()
{
	char str[100];
	long t,n,len;
	scanf("%ld",&t);
	getchar();
	getchar();
	while(t--)
	{
		n=0;
		while(gets(str) && str[0]!='\0')
		{
			a[n++]=atol(str);
		}
		len=lenlis(n);
		printf("Max hits: %ld\n",len);
		printlis(n,len);
		if(t)
		{
			printf("\n");
			//getchar();
		}
	}
	return 0;
}

