#include<stdio.h>
#include<string.h>
long dp[75][75],p;
long find(long n,long t)
{
    long i,j,k;
    dp[0][0]=1;
	for(j=1;j<=n;j++)
	{
        for(k=1;k<=t;k++)
        {
            dp[j][k]=0;
    	    for(i=p;i<=k;i++)
		        dp[j][k]+=dp[j-1][k-i];
        }
	}
	return dp[n][t];
}
int main()
{
	long cas,n,t;
	scanf("%ld",&cas);
	while(cas--)
	{
	//	memset(dp,-1,sizeof(dp));
		scanf("%ld %ld %ld",&n,&t,&p);
		printf("%ld\n",find(n,t));
	}
	return 0;
}
