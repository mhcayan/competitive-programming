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
#define mod 1000000007
const int inf=2000000000;
int pr[5000009];
ubig dp[5000009];
void sieve(int n)
{
     int i,m,j;
     m=2236;
     for(i=1;i<=n;i++)
         pr[i]=1;
     for(i=4;i<=n;i+=2)
         pr[i]=0;
     for(i=3;i<=m;i+=2)
     {
         if(pr[i]==1)
         {
             for(j=i*i;j<=n;j+=i+i)
                 pr[j]=0;
         }
     }
     dp[1]=1;
     for(i=2;i<=n;i++)
     {
         pr[i]+=pr[i-1];
         dp[i]=(dp[i-1]*pr[i])%mod;
     }
}
int main()
{
    int n,t;
    sieve(5000000);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%llu\n",dp[n]);
    }
    return 0;
}
