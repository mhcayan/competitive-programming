#include<stdio.h>
long C,E,cost[110][110],memo[110][1100],term[1110];
#define MAX(a,b) a>b?a:b
long dp(long cur,long trip)
{
	long p,i;
	if(memo[cur][trip]!=-1)
		return memo[cur][trip];
	if(trip==1)
	{
		p=-99999;
		for(i=1;i<=E;i++)
			p=MAX(cost[cur][term[i]],p);
	}
	else
	{
		p=-99999;
		for(i=1;i<=C;i++)
		{
			if(i!=cur)
			    p=MAX(p,cost[cur][i]+dp(i,trip-1));
		}
	}
	memo[cur][trip]=p;
	return p;
}
int main()
{
	long S,T,i,j;
	while(scanf("%ld %ld %ld %ld",&C,&S,&E,&T))
	{
		if(!C && !S && !E && !T)
			break;
		for(i=1;i<=C;i++)
		{
			for(j=1;j<=C;j++)
			    scanf("%ld",&cost[i][j]);
		}
		for(i=1;i<=E;i++)
			scanf("%ld",&term[i]);
		for(i=1;i<=C;i++)
			for(j=1;j<=T;j++)
				memo[i][j]=-1;
		printf("%ld\n",dp(S,T));
	}
	return 0;
}