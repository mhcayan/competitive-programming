#include<stdio.h>
long memo[10001];
long fun(long n)
{
	if(memo[n]==-1)
		return memo[n]=(fun(n-1) + fun(n-2) + fun(n-3) + fun(n-4) + fun(n-5) + fun(n-6))%10000007;
	return memo[n];
}
int main()
{
	long c,t,n,i;
	scanf("%ld",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%ld %ld %ld %ld %ld %ld %ld",&memo[0],&memo[1],&memo[2],&memo[3],&memo[4],&memo[5],&n);
		memo[0]%=10000007;
		memo[1]%=10000007;
		memo[2]%=10000007;
		memo[3]%=10000007;
		memo[4]%=10000007;
		memo[5]%=10000007;
		for(i=6;i<=n;i++)
			memo[i]=-1;
		printf("Case %ld: %ld\n",t, fun(n));
	}
	return 0;
}
