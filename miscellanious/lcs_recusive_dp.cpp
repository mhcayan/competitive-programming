#include<stdio.h>
#include<string.h>
char a[1000],b[1000];
long dp[1000][1000];
long max(long x,long y)
{
	return x>y?x:y;
}
long lcs(long i,long j)
{
	if(i<0 || j<0)
		return 0;
	if(dp[i][j]>=0)
		return dp[i][j];
	if(a[i]==b[j])
		return dp[i][j]=1+lcs(i-1,j-1);
	else
		return dp[i][j]=max(lcs(i,j-1),lcs(i-1,j));
}

int main()
{
	long l1,l2,i,j;
	while(gets(a))
	{
		gets(b);
		l1=strlen(a);
		l2=strlen(b);
		for(i=0;i<=l1;i++)
		{
			for(j=0;j<=l2;j++)
				dp[i][j]=-1;
		}
		printf("%ld\n",lcs(l1-1,l2-1));
	}
	return 0;
}
