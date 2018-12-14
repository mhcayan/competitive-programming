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
#define max(a,b) ((a)>(b)?(a):(b))
#define eps 1e-11
int dp[205][105],a[205][105],m,n;
int find(int i,int j)
{
	if(i==0 || i>m || j==0)
		return 0;
	if(i<n)
	{
		if(j>i)
		    return 0;
	    if(!dp[i][j])
	        dp[i][j]=a[i][j]+max(find(i+1,j),find(i+1,j+1));
	    return dp[i][j];
	}
	else
	{
		if(j>m+1-i)
			return 0;
		if(!dp[i][j])
		    dp[i][j]=a[i][j]+max(find(i+1,j-1),find(i+1,j));
		return dp[i][j];
	}

}
int main()
{
	int cas,t,i,j;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
    {
		scanf("%d",&n);
		m=2*n-1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				dp[i][j]=0;
			    scanf("%d",&a[i][j]);
			}
		}
		for(;i<=m;i++)
		{
			for(j=1;j<=m+1-i;j++)
			{
				dp[i][j]=0;
				scanf("%d",&a[i][j]);
			}
		}
		printf("Case %d: %d\n",t,find(1,1));
    }
    return 0;
}
