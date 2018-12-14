#include<stdio.h>
long a[100],l[100],b[100];
long lenlis(long n)
{
	long i,j;
	for(i=0;i<n;i++)
		l[i]=1;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]>a[i] && l[j]<l[i]+1)
				l[j]=l[i]+1;
		}
	}
	long maxl=l[0];
	for(i=1;i<n;i++)
	{
		if(l[i]>maxl)
			maxl=l[i];
	}
	return maxl;
}
long printlis(long n,long len)
{
	long i,j,top;
	i=0;
	for(j=1;j<n;j++)
	{
		if(l[j]>l[i])
			i=j;
	}
	top=l[i]-1;
	b[top]=a[i];
	top--;
	for(j=i-1;j>=0;j--)
	{
		if(a[j]<a[i] && l[j]==l[i]-1)
		{
			i=j;
			b[top]=a[j];
			top--;
			if(top<0)
				break;
		}
	}
	for(i=0;i<len;i++)
	{
		printf("%ld ",b[i]);
	}
	printf("\n");
	return 0;
}




int main()
{
	long len,i,n;
	scanf("%ld",&n);
	for(i=0;i<n;i++)
		scanf("%ld",&a[i]);
	len=lenlis(n);
	printf("%ld\n",len);
	printlis(n,len);
	return 0;
}
