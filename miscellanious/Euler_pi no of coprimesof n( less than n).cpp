#include<stdio.h>
long E[500000];
bool flag[1000000];
void sieve(long n)
{
	long i,j;
/*	for(i=2;i<=n;i++)
	{
		E[i]=n;
	}*/
	for(i=2;i<=n;i++)
	{
		if(flag[i]==0)
		{
			E[i]=i-1;
			for(j=i+i;j<=n;j+=i)
			{
				if(flag[j]==0)
				{
					E[j]=j;
				    flag[j]=1;
				}
				E[j]/=i;
				E[j]*=(i-1);
				
			}
		}
	}
}

int main()
{
	long n;
	sieve(100000);
	while(scanf("%ld",&n)==1)
	{
		printf("no. of coprimes of n(less than n) = %ld\n",E[n]);
	}
	return 0;
}