#include<stdio.h>
#include<string.h>
long dp[75][75],p;
long find(long n,long t)
{
	if(n==0)
	{
		if(t==0)
			return 1;
		else
			return 0;
	}
	if(dp[n][t]>-1)
		return dp[n][t];
	dp[n][t]=0;
	long i;
	for(i=p;i<=t;i++)
	{
		dp[n][t]+=find(n-1,t-i);
	}
	return dp[n][t];
}
int main()
{
	long cas,n,t,i,j;
	scanf("%ld",&cas);
	while(cas--)
	{
	//	memset(dp,-1,sizeof(dp));
		scanf("%ld %ld %ld",&n,&t,&p);
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=t;j++)
				dp[i][j]=-1;
		}
		printf("%ld\n",find(n,t));
	}
	return 0;
}
