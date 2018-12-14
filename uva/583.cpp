#include<stdio.h>
#include<math.h>
bool flag[50000];
long p[50000];
int sieve()
{
	long i,j,k=0;
	p[k++]=2;
	for(i=3;i<=219;i+=2)
	{
		if(flag[i]==0)
			p[k++]=i;
		for(j=i*i;j<=47961;j+=i+i)
			flag[j]=1;
	}
	for(;i<=47961;i+=2)
	{
		if(flag[i]==0)
			p[k++]=i;
	}
	return 0;
}
int divis(long x)
{
	long m,i,n,k=0,d[50000];
	n=x>0?x:-x;
	m=sqrt(n);
	for(i=0;p[i]<=m;i++)
	{
		if(n%p[i]==0)
		{
			while(n%p[i]==0)
			{
				n=n/p[i];
				d[k++]=p[i];
			}
			m=sqrt(n);
		}
	}
	if(n>1)
		d[k++]=n;
	if(x>0)
	{
		printf("%ld = %ld",x,d[0]);
		for(i=1;i<k;i++)
			printf(" x %ld",d[i]);
	}
	else
	{
		printf("%ld = -1",x);
		for(i=0;i<k;i++)
			printf(" x %ld",d[i]);
	}
	printf("\n");
	return 0;
}
int main()
{
	long n;
	sieve();
	while(scanf("%ld",&n))
	{
		if(n==0)
			break;
		divis(n);
	}
	return 0;
}
