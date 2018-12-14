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
int dp[1002];
bool pal[1000][1000];
char a[1003];
int main()
{
	int cs,tc,m,n,i,j,l;
	scanf("%d",&cs);
    for(tc=1;tc<=cs;tc++)
    {
		scanf("%s",&a);
		l=strlen(a)-1;
		for(i=0;i<=l;i++)
			pal[i][i]=1;
		dp[l+1]=0;
		dp[l]=1;
		for(i=l-1;i>=0;i--)
		{
			dp[i]=dp[i+1]+1;
			for(j=i+1;j<=l;j++)
			{
				pal[i][j]=0;
				if(a[i]==a[j])
				{
				    m=i+1;
				    n=j-1;
					if(m<n)
					{
						if(pal[m][n])
						{
							pal[i][j]=1;
							if(dp[i]>1+dp[j+1])
								dp[i]=1+dp[j+1];
						}
					}
					else
					{
						pal[i][j]=1;
						if(dp[i]>1+dp[j+1])
							dp[i]=1+dp[j+1];
					}
				}
			}
		}
		printf("Case %d: %d\n",tc,dp[0]);
    }
    return 0;
}
