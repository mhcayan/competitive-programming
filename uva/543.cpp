#include<stdio.h>
int sieve();
bool status[1000001];
long a[1000000];
int main()
{
	long c,n,i,flag;
	c=sieve();
	while(scanf("%ld",&n))
	{
		if(n==0)
			break;
		flag=1;
		for(i=0;a[i]<n;i++)
		{
			if(status[n-a[i]]==0)
			{
				printf("%ld = %ld + %ld\n",n,a[i],n-a[i]);
				flag=0;
				break;
			}
		}
		if(flag)
			printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}
int sieve()
{
	long c=0,i,j;
    for(i=0;i<=1000000;i+=2) 
		status[i]=1;
	for(i=3;i<=1000000;i+=2)
	{
		if(status[i]==0)
		{
			a[c++]=i;
			if(i<=1000)
			{
				for(j=i*i;j<=1000000;j+=2*i)
					status[j]=1;
			}
		}
	}
	return c;
}
