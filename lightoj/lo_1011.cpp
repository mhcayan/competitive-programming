#include<stdio.h>
#include<string.h>
#define CLR(a) memset(a,0,sizeof(a))
int dp[1<<17],a[17][17],n;
int find(int p,int now)
{
	if(p==n)
        return 0;
	if(now==(1<<n)-1)
		return 0;	
	if(dp[now])
		return dp[now];	
	int i,next,v;
	for(i=0;i<n;i++)
	{
		if(now & 1<<i)
			continue;
		next=now|(1<<i);
		v=a[p][i]+find(p+1,next);
		if(v>dp[now])
			dp[now]=v;
	}
	return dp[now];
}
int main()
{
	int cas,t,i,j;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
    {
        CLR(dp);
		scanf("%d",&n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		printf("Case %d: %d\n",t,find(0,0));
			
    }
    return 0;
}
