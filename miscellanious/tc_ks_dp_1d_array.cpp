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
long a[10000],dp[1000];
long find(long k,long m)
{
     long i,j;
     dp[0]=1;
     for(i=1;i<=m;i++)
         dp[i]=0;
     for(i=1;i<=k;i++)
     {
         for(j=m;j>=1;j--)
         {
             if(a[i]>j)
                 dp[j]=dp[j];
             else
                 dp[j]=dp[j]+dp[j-a[i]];
         }
     }
     return dp[m];
}
int main()
{
    long cas,k,m,i;
    while(scanf("%ld",&k)==1)
    {
        for(i=1;i<=k;i++)
            scanf("%ld",&a[i]);
        scanf("%ld",&cas);
        while(cas--)
        {
            //SET(dp);
            scanf("%ld",&m);
            printf("%ld\n",find(k,m));
        }
    }
    return 0;
}
