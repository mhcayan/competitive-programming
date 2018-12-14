#include<stdio.h>
long a[40000];
bool status[40000];
long sieve();
int main()
{
	long n,m,i,count;
	sieve();
	while(scanf("%ld",&n))
	{
		if(n==0)
			break;
		m=n/2;
		count=0;
		for(i=0;a[i]<=m;i++)
		{
			if(status[n-a[i]]==0)
				count++;
		}
		printf("%ld\n",count);
	}
	return 0;
}
long sieve()
{
	long c=0,i,j;
	for(i=4;i<32769;i+=2)
		status[i]=1;
	a[c++]=2;
	for(i=3;i<32769;i+=2)
	{
		if(status[i]==0)
		{
			a[c++]=i;
			if(i<182)
			{
				for(j=i*i;j<32769;j+=2*i)
					status[j]=1;
			}
		}
	}
	return c;
}