#include<stdio.h>
#include<string.h>
int dp[500][500];
int cal(int sum,int max)
{
	if(dp[sum][max]>=0)
		return dp[sum][max];
	if(sum==0)
		return 1;
	if(sum<0||max==0)
		return 0;
	return dp[sum][max]=cal(sum-max,max)+cal(sum,max-1);
}
int main()
{
	int n;
	memset(dp,-1,sizeof(dp));
	while(scanf("%d",&n)==1)
	{
		printf("total way=%d\n",cal(n,n-1));
	}
	return 0;
}