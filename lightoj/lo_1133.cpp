#include<stdio.h>
long a[105];
int sum(long d,long n)
{
	long i;
	for(i=0;i<n;i++)
		a[i]+=d;
	return 0;
}
int mul(long d,long n)
{
	long i;
	for(i=0;i<n;i++)
		a[i]*=d;
	return 0;
}
int div(long d,long n)
{
	long i;
	for(i=0;i<n;i++)
		a[i]/=d;
	return 0;
}
int swap(long i,long j)
{
	long t;
	t=a[i];a[i]=a[j];a[j]=t;
	return 0;
}
int rev(long n)
{
	long i,m,t;
	m=n/2;
	n--;
	for(i=0;i<m;i++)
	{
		t=a[i];
		a[i]=a[n-i];
		a[n-i]=t;
	}
	return 0;
}
int main()
{
	char ch;
	long cas,t,i,j,d,n,m;
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%ld %ld",&n,&m);
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		while(m--)
		{
			getchar();
			scanf("%c",&ch);
			if(ch=='S')
			{
				scanf("%ld",&d);
				sum(d,n);
			}
			else if(ch=='M')
			{
				scanf("%ld",&d);
				mul(d,n);
			}
			else if(ch=='D')
			{
				scanf("%ld",&d);
				div(d,n);
			}
			else if(ch=='P')
			{
				scanf("%ld %ld",&i,&j);
				swap(i,j);
			}
			else
				rev(n);
		}
		n--;
		printf("Case %ld:\n",t);
		for(i=0;i<n;i++)
			printf("%ld ",a[i]);
		printf("%ld\n",a[i]);
	}
	return 0;
}

