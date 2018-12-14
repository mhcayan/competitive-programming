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
long T,F,B,dp[14][1<<14],a[14];
const int inf=2000000000;
long find(long t,long now)
{
     long i;
     if(t==0)
     {
         long f,b,m;
         f=1;
         m=1;
         //printf("yes\n");
         /*for(i=1;i<=T;i++)
         printf("%ld",a[i]);
         printf("\n");*/
         for(i=2;i<=T;i++)
         {
             if(a[i]>a[m])
             {
                 f++;
                 m=i;
             }
         }
         if(f!=F)
             return 0;
         b=1;
         m=T;
         for(i=T-1;i>0;i--)
         {
             if(a[i]>a[m]);
             {
                 m=i;
                 b++;
             }
         }
         if(b!=B)
             return 0;
         return 1;
     }
     if(t==1)
     printf("%ld\n",now);
     if(dp[t][now]>-1)
         return dp[t][now];
         
     dp[t][now]=0;
     long next;
     for(i=1;i<=T;i++)
     {
         if(now & (1<<i))
             continue;
         a[t]=i;
        // if(t==2)
         //printf("%ld%ld\n",a[T-1],a[T]);
         next=now | (1<<i);
         dp[t][now]+=find(t-1,next);
     }
     return dp[t][now];
}
int main()
{
    long tc,cow=0;
    scanf("%ld",&tc);
    while(tc--)
    {
        SET(dp);
        scanf("%ld %ld %ld",&T,&F,&B);
        printf("%ld\n",find(T,cow));
    }
    return 0;
}
