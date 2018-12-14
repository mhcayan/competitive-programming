#include<stdio.h>
#include<math.h>
long dp[102][102];
void fact()
{
	long i,k,n,m;
	dp[2][2]=1;
	for(k=3;k<101;k++)
	{
		for(i=2;i<k;i++)
			dp[k][i]=dp[k-1][i];
		n=k;
		m=sqrt(n);
		for(i=0;p[i]<=m;i++)
		{
			if(n%p[i]==0)
			{
				while(n%p[i]==0)
				{
					n/=p[i];
					dp[k][p[i]]++;
				}
			}
			m=sqrt(n);
		}
		if(n>1)
			dp[k][n]++;
	}
}
int main()
{
	long cas,t,i,;
	scanf("%ld",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%ld",&n);
		printf("Case %ld: %ld = ",t,n);
		for(i=2;i<=n;i++)
		{
			if(dp[n][i])
				printf("%ld (%ld)",i,dp[n][i]);
		}
		for(;i<=n;i++)
		{
			if(dp[n][i])
				printf(" * %ld (%ld)",i,dp[n][i]);
		}
		printf("\n");
	}
	return 0;
}

