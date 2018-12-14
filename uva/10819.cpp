#include<stdio.h>
#define max(a,b) a>b?a:b
long ks(long i,long c);
long n,memo[101][10001],w[1000],v[1000];
int main()
{
	long c,i,j;
	while(scanf("%ld %ld",&c,&n)==2)
	{
		if(c>1800)
			c+=200;
		for(i=1;i<=n;i++)
		{
			scanf("%ld %ld",&w[i],&v[i]);
			for(j=1;j<=c;j++)
				memo[i][j]=-1;
		}
		printf("%ld\n",ks(1,c));
	}
	return 0;
}
long ks(long i,long c)
{
	if(i>n)
		return 0;
	if(memo[i][c]>=0)
		return memo[i][c];
	if(w[i]>c)
		return memo[i+1][c]=ks(i+1,c);
	else
	{
		memo[i+1][c]=ks(i+1,c);
		memo[i+1][c-w[i]]=ks(i+1,c-w[i]);
		return max(memo[i+1][c],v[i]+memo[i+1][c-w[i]]);
	}
}
