#include<stdio.h>
#include<math.h>
bool flag[10000005];
long pr[666666];
void sieve(long n)
{
	long m,i,c,j;
	m=sqrt(n);
	for(i=4;i<=n;i+=2)
		flag[i]=1;
	pr[0]=2;
	c=1;
	for(i=3;i<=m;i+=2)
	{
		if(flag[i]==0)
		{
			pr[c++]=i;
			for(j=i*i;j<=n;j+=i+i)
			{
				flag[j]=1;
			}
		}
	}
	for(;i<=n;i+=2)
	{
		if(flag[i]==0)
			pr[c++]=i;
	}
}
int main()
{
	long cas,t,n,m,count,i;
	scanf("%ld",&cas);
	sieve(10000000);
	for(t=1;t<=cas;t++)
	{
		scanf("%ld",&n);
		m=n/2;
		count=0;
		for(i=0;pr[i]<=m;i++)
		{
			if(flag[n-pr[i]]==0)
				count++;
		}
		printf("Case %ld: %ld\n",t,count);
	}
	return 0;
}
