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
long a[10000],dp[50][1000];
long find(long k,long m)
{
     if(m==0)
         return 1;
     if(m<0 || k<0)
         return 0;
     if(dp[k][m]>-1)
         return dp[k][m];
     return dp[k][m]=find(k-1,m-a[k])+find(k-1,m);
}
int main()
{
    long cas,k,m,i;
    while(scanf("%ld",&k)==1)
    {
        for(i=0;i<k;i++)
            scanf("%ld",&a[i]);
        scanf("%ld",&cas);
        while(cas--)
        {
            SET(dp);
            scanf("%ld",&m);
            printf("%ld\n",find(k-1,m));
        }
    }
    return 0;
}
