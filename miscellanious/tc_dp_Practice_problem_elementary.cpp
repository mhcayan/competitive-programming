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
long dp[10000];
vector<long>edge[1000],cost[1000];
long find(long n)
{
     if(n==1)
         return 0;
     long i,m,res;
     dp[n]=inf;
     for(i=0;i<edge[n].size();i++)
     {
         m=edge[n][i];
         if(dp[m]==-1)
             res=find(m)+cost[n][i];
         else if(dp[m]!=inf)
             res=dp[m]+cost[n][i];
         else
             continue;
         if(res<dp[n])
             dp[n]=res;
     }
     return dp[n];
}
int main()
{
    long i,e,u,v,n,c;
    while(scanf("%ld %ld",&n,&e)==2)
    {
        for(i=1;i<=n;i++)
        {
            edge[i].clear();
            cost[i].clear();
        }
        for(i=0;i<e;i++)
        {
            scanf("%ld %ld %ld",&u,&v,&c);
            edge[u].pb(v);
            edge[v].pb(u);
            cost[u].pb(c);
            cost[v].pb(c);
        }
        SET(dp);
        printf("%ld\n",find(n));
        printf("%ld %ld %ld\n",dp[1],dp[2],dp[3]);
    }
    return 0;
}
