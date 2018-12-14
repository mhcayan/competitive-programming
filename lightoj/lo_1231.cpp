#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cctype>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iterator>
using namespace std;
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
#define mod 100000007
const int inf=2000000000;
int dp[1005][55],coin[55],av[55];
int find(int k,int m)
{
	if(k==0)
		return 1;
	if(k<0 || m<0)
		return 0;
	if(dp[k][m]>-1)
		return dp[k][m];
	dp[k][m]=0;
	int i;
	for(i=0;i<=av[m];i++)
	{
		if(i*coin[m]<=k)
			dp[k][m]=(dp[k][m]+find(k-coin[m]*i,m-1))%mod;
		else
			break;
	}
	return dp[k][m];
}
int main()
{
	int cas,t,n,k,i;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
    {
		SET(dp);
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&coin[i]);
		for(i=0;i<n;i++)
			scanf("%d",&av[i]);
		printf("Case %d: %d\n",t,find(k,n-1));
    }
    return 0;
}
