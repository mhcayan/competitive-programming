#include<stdio.h>
long a[100000],step;
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
	printf("\nSteps=%ld",step);
	return 0;
}
int mergesort(long i,long k)
{
	long j;
	if(i<k)
	{
		j=(i+k)/2;
		step++;
		mergesort(i,j);
		step++;
		mergesort(j+1,k);
		step++;
		merge(i,j,k);
		step++;
	
	}
	return 0;
}
int merge(long p,long q,long r)
{
	long n1,n2,i;
	n1=q-p+1;
	n2=r-q;
	step+=2;
	long m[10000],n[10000];
	for(i=0,step++;i<n1;i++,step++)
	{
		m[i]=a[p+i];
		step++;
	}
	m[i]=-1;
	for(i=0,step++;i<n2;i++,step++)
	{
		step++;
		n[i]=a[q+1+i];
	}
	n[i]=-1;
	long j=0,k=0;
	while(m[j]!=-1&&n[k]!=-1)
	{
		if(m[j]<n[k])
		{
			a[p]=m[j];
			j++;
			p++;
			step++;
		}
	    else
		{
			a[p]=n[k];
			k++;
			p++;
			step++;
		}
	}
	if(m[j]==-1)
	{
		while(n[k]!=-1)
		{
			a[p]=n[k];
			p++;
			k++;
			step++;
		}
	}
	if(n[k]==-1)
	{
		while(m[j]!=-1)
		{
			a[p]=m[j];
			p++;
			j++;
			step++;
		}
	}
	return 0;
}

