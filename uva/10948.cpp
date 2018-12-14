#include<stdio.h>
long sieve();
long a[1000000];
bool status[1000002];
int main()
{
	sieve();
	bool flag;
	long n,m,i;
	while(scanf("%ld",&n))
	{
		if(n==0)
			break;
		m=n/2;
		flag=1;
		for(i=0;a[i]<=m;i++)
		{
			if(status[n-a[i]]==0)
			{
				printf("%ld:\n%ld+%ld\n",n,a[i],n-a[i]);
				flag=0;
				break;
			}
		}
		if(flag)
			printf("%ld:\nNO WAY!\n",n);
	}
	return 0;
}
long sieve()
{
	long i,j,c=0;
	for(i=4;i<1000001;i+=2)
		status[i]=1;
	a[c++]=2;
	for(i=3;i<1000000;i+=2)
	{
		if(status[i]==0)
		{
			a[c++]=i;
			if(i<1000)
			{
				for(j=i*i;j<1000000;j+=2*i)
					status[j]=1;
			}
		}
	}
	return c;
}
