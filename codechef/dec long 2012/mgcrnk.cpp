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
#include<set>
using namespace std;
#define big long long
#define ubig unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
#define mod 100000007
const int inf=2000000;
bool vis[103][103];
int dp[103][103],n;
int find(int i,int j)
{
    if(i>n || j>n)
        return -inf;
    if(i==n && j==n)
        return 0;
    if(vis[i][j])
        return dp[i][j];
    vis[i][j]=1;
    return dp[i][j]+=max(find(i+1,j),find(i,j+1));
}
int main()
{
    int cas,i,j,ans;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                scanf("%d",&dp[i][j]);
                vis[i][j]=0;
            }
        ans=find(1,1);
        if(ans<0)
            printf("Bad Judges\n");
        else
            printf("%.7lf\n",(double)ans/(n+n-3));
    }
    return 0;
}
