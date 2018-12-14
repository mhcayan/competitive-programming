#include<stdio.h>
long a[10000];
int mergesort(long,long);
int merge(long,long,long);
int main()
{
	long n;
	scanf("%ld",&n);
	for(long i=0;i<n;i++)
		scanf("%d",&a[i]);
	mergesort(0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%ld ",a[i]);
		if((i+1)%15==0)
			printf("\n");
	}
	return 0;
}
int mergesort(long i,long k)
{
	long j;
	if(i<k)
	{
		j=(i+k)/2;
		mergesort(i,j);
		mergesort(j+1,k);
		merge(i,j,k);
	
	}
	return 0;
}
int merge(long p,long q,long r)
{
	long n1,n2;
	n1=q-p+1;
	n2=r-q;
	long m[10000],n[10000];
	for(long i=0;i<n1;i++)
		m[i]=a[p+i];
	m[i]=-1;
	for(i=0;i<n2;i++)
		n[i]=a[q+1+i];
	n[i]=-1;
	long j=0,k=0;
	while(m[j]!=-1&&n[k]!=-1)
	{
		if(m[j]<n[k])
		{
			a[p]=m[j];
			j++;
			p++;
		}
	    else
		{
			a[p]=n[k];
			k++;
			p++;
		}
	}
	if(m[j]==-1)
	{
		while(n[k]!=-1)
		{
			a[p]=n[k];
			p++;
			k++;
		}
	}
	if(n[k]==-1)
	{
		while(m[j]!=-1)
		{
			a[p]=m[j];
			p++;
			j++;
		}
	}
	return 0;
}

