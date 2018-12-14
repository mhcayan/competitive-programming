#include<stdio.h>
int main()
{
	unsigned long  c,t,n,i,memo[100000];
	scanf("%lu",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%lu %lu %lu %lu %lu %lu %lu",&memo[0],&memo[1],&memo[2],&memo[3],&memo[4],&memo[5],&n);
		memo[0]%=10000007;
		memo[1]%=10000007;
		memo[2]%=10000007;
		memo[3]%=10000007;
		memo[4]%=10000007;
		memo[5]%=10000007;
		for(i=6;i<=n;i++)
			memo[i]=(memo[i-1] + memo[i-2] + memo[i-3] + memo[i-4] + memo[i-5] + memo[i-6])%10000007;
		printf("Case %lu: %lu\n",t, memo[n]);
	}
	return 0;
}
