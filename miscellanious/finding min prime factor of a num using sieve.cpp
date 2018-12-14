#include<stdio.h>
long minf[100005];
bool flag[100005];
void sieve()
{
	long i,j;
	for(i=2;i<=100000;i+=2)
		minf[i]=2;

	for(i=3;i<=316;i+=2)
	{
		if(flag[i]==0)
		{
			minf[i]=i;
			for(j=i*i;j<=100000;j+=i+i)
			{
				if(flag[j]==0)
				{
					flag[j]=1;
					minf[j]=i;
				}
			}
		}
	}
	for(;i<=100000;i+=2)
	{
		if(flag[i]==0)
			minf[i]=i;
	}
}
int main()
{
	long n;
	sieve();
	while(scanf("%ld",&n)==1)
	{
		printf("%ld\n",minf[n]);
	}
	return 0;
}