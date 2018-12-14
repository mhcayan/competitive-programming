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
long dp[10000],a[1000];
long find(long n,long s)
{
     long i,j;
     dp[0]=0;
     for(i=1;i<=s;i++)
     {
         for(j=0;j<n;j++)
         {
             if(a[j]<=i)
             {
                 if(dp[i-a[j]]+1<dp[i])
                     dp[i]=dp[i-a[j]]+1;
             }
             else
                 break;
         }
     }
     return dp[s];
}
int main()
{
    long n,s,i,cas;
    while(scanf("%ld",&n)==1)
    {
        for(i=0;i<n;i++)
            scanf("%ld",&a[i]);
        scanf("%ld",&cas);
        while(cas--)
        {
            scanf("%ld",&s);
            dp[0]=0;
            for(i=1;i<=s;i++)
                dp[i]=inf;
            printf("total=%ld\n",find(n,s));
        }
    }
    return 0;
}
