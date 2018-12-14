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
#define big long long
#define ubig unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
#define mod 100000007
const int inf=2000000000;
long dp[103][100005][10],flag[100005];
long n,m,c[103],a[103];
long max(long a,long b)
{
	return a>b?a:b;
}
long find(long t,long i,long j)
{
	if(t==0)
		return 1;
	if(i==0 || j==0)
		return 0;
	if(dp[t][i][j]>-1)
		return dp[t][i][j];
	dp[t][i][j]=max(find(t-a[i],i,j-1),find(t,i-1,c[i-1]));
	if(dp[t][i][j]==1)
		flag[t]=1;
	return dp[t][i][j];
}
int main()
{
	long cas,tc,i,ans;
	scanf("%ld",&cas);
	for(tc=1;tc<=cas;tc++)
    {
		SET(dp);
		CLR(flag);
		scanf("%ld %ld",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);
		for(i=1;i<=n;i++)
			scanf("%ld",&c[i]);
		ans=0;
		find(m,n,c[n]);
		for(i=1;i<=m;i++)
		{
			if(flag[i])
				ans++;
		}
		printf("Case %ld: %ld\n",tc,ans);
    }
    return 0;
}
