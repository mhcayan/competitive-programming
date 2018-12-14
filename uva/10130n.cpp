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
long dp[1003][33];
int main()
{
	long tc,n,i,g,ans,w[1003],p[1003],c[103],maxc,j,x;
	scanf("%ld",&tc);
	while(tc--)
    {
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
			scanf("%ld %ld",&p[i],&w[i]);
		scanf("%ld",&g);
		ans=0;
		maxc=-inf;
		for(i=1;i<=g;i++)
		{
			scanf("%ld",&c[i]);
			if(c[i]>maxc)
				maxc=c[i];
		}
		for(i=1;i<=n;i++)
		{
		    for(j=1;j<=maxc;j++)
			{
			    if(w[i]>j)
				    dp[i][j]=dp[i-1][j];
			    else
				{
				    x=p[i]+dp[i-1][j-w[i]];
				    if(x>dp[i-1][j])
					    dp[i][j]=x;
				    else
					    dp[i][j]=dp[i-1][j];
				}
			}
		}
		for(i=1;i<=g;i++)
			ans+=dp[n][c[i]];
		printf("%ld\n",ans);
    }
    return 0;
}
