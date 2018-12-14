#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	long *x=(long *)a;
	long *y=(long *)b;
	return *x-*y;
}
int main()
{
	long m,n,i,j,a[20000],b[20000],sum,t;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld %ld",&m,&n);
		for(i=0;i<m;i++)
			scanf("%ld",&a[i]);
		for(j=0;j<n;j++)
			scanf("%ld",&b[j]);
		qsort(a,m,sizeof(long),cmp);
		qsort(b,n,sizeof(long),cmp);
		i=0;j=0;sum=0;
		while(i<m && j<n)
		{
			if(a[i]==b[j])
			{
				i++;
				j++;
			}
			else if(a[i]<b[j])
			{
				
				sum++;
				i++;
			}
			else
			{
				
				sum++;
				j++;
			}
		}
		if(i==m && j==n)
		{
		}
		else if(i==m)
			sum+=n-j;
		else
			sum+=m-i;
		printf("%ld\n",sum);
	}
	return 0;
}



