#include<stdio.h>
#include<string.h>
unsigned long dp[1<<17],n,a[100];
unsigned long find(unsigned long now)
{
	if(now==(1<<n)-1)
		return 0;
	if(dp[now]>-1)
		return dp[now];
	dp[now]=0;
	unsigned long i,j,k,next,v;
	for(i=0;i<n;i++)
	{
		if(now & 1<<i)
			continue;
		for(j=i+1;j<n;j++)
		{
			if(now & 1<<j)
				continue;
			for(k=j+1;k<n;k++)
			{
				if(now & 1<<k)
					continue;
				if(a[i]+a[j]+a[k]<20)
					continue;
				next=now|(1<<i)|(1<<j)|(1<<k);
				v=find(next);
				if(1+v>dp[now])
					dp[now]=1+v;
			}
		}
	}
	return dp[now];
}
int main()
{
	unsigned long i,t=1,now,m;
	while(scanf("%lu",&n) && n)
	{
		m=1<<n;
		for(i=0;i<=m;i++)
			dp[i]=-1;
		for(i=0;i<n;i++)
			scanf("%lu",&a[i]);
		now=0;
		printf("Case %lu: %lu\n",t++,find(now));
	}
	return 0;
}