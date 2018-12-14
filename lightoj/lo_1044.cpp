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
int dp[1002][1002];
bool pal[1002][1002];
char a[1003];
int find(int i,int j)
{
	if(dp[i][j])
		return dp[i][j];
	if(pal[i][j])
		return 1;
	dp[i][j]=inf;
	int x,k;
	for(k=i;k<j;k++)
	{
		if(pal[i][k])
		{
		    x=find(k+1,j);
		    if(x<dp[i][j])
			    dp[i][j]=x;
		}
	}
	return dp[i][j]=1+dp[i][j];
}
int main()
{
	int cs,tc,m,n,i,j,l;
	scanf("%d",&cs);
    for(tc=1;tc<=cs;tc++)
    {
		scanf("%s",&a);
		l=strlen(a)-1;
		for(i=0;i<=l;i++)
		{
			dp[i][i]=1;
			pal[i][i]=1;
		}
		for(i=l-1;i>=0;i--)
		{
			for(j=i+1;j<=l;j++)
			{
				dp[i][j]=0;
				pal[i][j]=0;
				if(a[i]==a[j])
				{
				    m=i+1;
				    n=j-1;
					if(m<n)
					{
						if(pal[m][n])
							pal[i][j]=1,dp[i][j]=1;
					}
					else
						pal[i][j]=1,dp[i][j]=1;
				}
			}
		}
		printf("Case %d: %d\n",tc,find(0,l));
    }
    return 0;
}
