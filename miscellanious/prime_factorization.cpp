#include<stdio.h>
#include<math.h>
long p[100000];
bool flag[100000];
int sieve(long n)
{
	long m,k,i,j;
	k=0;
	p[k++]=2;
	m=sqrt(n);
	for(i=3;i<=m;i+=2)
	{
		if(flag[i]==0)
		{
		//	printf("%ld\n",i);
			p[k++]=i;
			for(j=i*i;j<=n;j+=i+i)
				flag[j]=1;
		}
	}
	for(;i<=n;i+=2)
	{
		if(flag[i]==0)
		{
		//	printf("%ld\n",i);
			p[k++]=i;
		}
	}
	return 0;
}
int primefactorise(long n)
{
	long m,i,k=0,factor[10000];
	m=sqrt(n);
	sieve(m+30);
	for(i=0;p[i]<=m;i++)
	{
		if(n%p[i]==0)
		{
			while(n%p[i]==0)
			{
				n=n/p[i];
				factor[k++]=p[i];
			}
			m=sqrt(n);//this can speed up more
		}
	}
	if(n>1)
		factor[k++]=n;
	for(i=0;i<k;i++)
		printf("%ld ",factor[i]);
	printf("\n");
	return 0;
}
int main()
{
	long n;
	while(scanf("%ld",&n)==1)
	{
		primefactorise(n);
	}
	return 0;
}
