#include<stdio.h>
#include<string.h>
int dp[1000][50],a[100],n;
int find(int t,int m)
{
	if(t==0)
		return 1;
	if(t<0 || m<0)
		return 0;
	if(dp[t][m]>-1)
		return dp[t][m];
	return dp[t][m]=find(t-a[m],m)+find(t,m-1);
}
/*int find( int n, int m )
{
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    if(m < 0 && n >= 1)
        return 0;
    return find( n, m - 1 ) + find( n - a[m], m );
}*/
int main()
{
	int i,t;
	while(scanf("%d",&n)==1)
	{
		memset(dp,-1,sizeof(dp));
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&t);
		printf("%d\n",find(t,n-1));
	}
	return 0;
}
