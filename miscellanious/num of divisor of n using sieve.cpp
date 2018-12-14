#include<stdio.h>
bool flag[1000000];
long D[200000];
void sieve(long n)
{
	long i,j,k,m,c;
	m=n/2;
	for(i=2;i<=m;i++)
	{
		if(flag[i]==0)
		{
			D[i]=2;
			for(j=i+i;j<=n;j+=i)
			{
				if(flag[j]==0)
				{
					flag[j]=1;
					D[j]=1;
				}
				k=j;
				c=1;
				while(k%i==0)
				{
					c++;
					k=k/i;
				}
				D[j]*=c;
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
		printf("%ld\n",D[n]);
	}
	return 0;
}
