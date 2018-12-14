#include<stdio.h>
#include<string.h>
#include<math.h>
unsigned long x[1000],y[1000],i,n,m;
double dp[1<<17];
char s[1000];
unsigned long square(unsigned long z)
{
	return z*z;
}
double make(unsigned long now)
{
	if(now==((1<<m)-1))
		return 0;
	if(dp[now]>-1)
		return dp[now];
	dp[now]=1e9;
	unsigned long i,j;
	double v,p;
	unsigned long next;
	for(i=0;i<m;i++)
	{
		if(now & (1<<i))
			continue;
		for(j=i+1;j<m;j++)
		{
			if(now & (1<<j))
				continue;
			v=sqrt(square(x[i]-x[j])+square(y[i]-y[j]));
			next=now|(1<<i)|(1<<j);
			p=make(next);
			if(dp[now]>v+p)
			    dp[now]=v+p;
		}
	}
	return dp[now];
}
int main()
{
	//printf("%ld\n",sizeof(dp)/sizeof(double));
	unsigned long now,t=1;
	while(scanf("%lu",&n) && n)
	{
		getchar();
		m=2*n;
		memset(dp,-1,sizeof(dp));
		//for(i=0;i<65600;i++)
		//	dp[i]=-1;
		for(i=0;i<m;i++)
		{
			scanf("%s %lu %lu",&s,&x[i],&y[i]);
			getchar();
		}
		now=0;
			printf("Case %lu: %.2lf\n",t++,make(now));

	}
	return 0;
}
