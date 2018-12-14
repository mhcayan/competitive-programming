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
long dp[33][1003],w[1003],p[1003];
inline long max(long a,long b)
{
	return a>b?a:b;
}
long find(long c,long n)
{
	if(n==0)
		return 0;
	if(dp[c][n]>-1)
		return dp[c][n];
	if(w[n]>c)
		return dp[c][n]=find(c,n-1);
	return dp[c][n]=max(find(c,n-1),p[n]+find(c-w[n],n-1));
}
int main()
{
	long tc,n,i,g,ans,c;
	scanf("%ld",&tc);
	while(tc--)
    {
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
			scanf("%ld %ld",&p[i],&w[i]);
		scanf("%ld",&g);
		ans=0;
		SET(dp);
		while(g--)
		{
			scanf("%ld",&c);
			ans+=find(c,n);
		}
		printf("%ld\n",ans);
    }
    return 0;
}
