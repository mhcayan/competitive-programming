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
long dp[30][205],a[25][25];
inline long min(long a,long b)
{
     return a<b?a:b;
}
long find(long n,long t)
{
     if(n==0)
         return t;
     if(t<=0)
         return t;
     if(dp[n][t]>-1)
         return dp[n][t];
     dp[n][t]=inf;
     long i,ans;
     for(i=1;i<=a[n][0];i++)
     {
         ans=find(n-1,t-a[n][i]);
         if(ans>-1)
             dp[n][t]=min(dp[n][t],ans);
     }
     return dp[n][t];
  
}
int main()
{
    long tc,l,T,N,mt,i,j,k,min;
    scanf("%ld",&tc);
    while(tc--)
    {
        SET(dp);
        scanf("%ld %ld",&T,&N);
        mt=0;
        for(i=1;i<=N;i++)
        {
            min=inf;
            scanf("%ld",&k);
            a[i][0]=k;
            for(j=1;j<=k;j++)
            {
                scanf("%ld",&a[i][j]);
                if(a[i][j]<min)
                    min=a[i][j];
            }
            mt+=min;
        }
        if(mt>T)
            printf("no solution\n");
        else
        {
            
            printf("%ld\n",T-find(N,T));
        }
    }
    return 0;
}
