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
const long z=26;
const int inf=2000000000;
long dp[355][27][27];
long find(long s,long l,long p)
{
     if(l==0)
     {
         if(s==0)
             return 1;
         return 0;
     }
     if(s<=0 || p==0)
         return 0;
     if(dp[s][l][p]>-1)
         return dp[s][l][p];
     dp[s][l][p]=0;
     long i;
     for(i=0;i<p;i++)
         dp[s][l][p]+=find(s-p+i,l-1,p-i-1);
     return dp[s][l][p];
   
}
int main()
{
    long l,s,tc=1;
    SET(dp);
    while(scanf("%ld %ld",&l,&s))
    {
        if(l==0 && s==0)
            break;
        if(l>26 || s>351)
            printf("Case %ld: 0\n",tc++);
        else if(((52-l+1)*l)/2<s)
            printf("Case %ld: 0\n",tc++);    
        else
        {
            printf("Case %ld: %ld\n",tc++,find(s,l,z));
        }
    }
    return 0;
}
