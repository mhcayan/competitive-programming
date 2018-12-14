#include<stdio.h>
//#define MAX(a,b) (a>b)?a:b
long n,memo[100][100],a[100][100];
long max(long p,long q)
{
	if(p>q)
		return p;
	else
		return q;
}
long sum(long i,long j)
{
	if(i==n)
		return a[i][j];
	else if(memo[i][j])
		return memo[i][j];
	else
		return memo[i][j]=a[i][j]+max(sum(i+1,j),sum(i+1,j+1));
}
int  main()
{
	long t,i,j;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				scanf("%ld",&a[i][j]);
				memo[i][j]=0;
			}
		}
		
		printf("%ld\n",sum(1,1));
	}
	return 0;
}



