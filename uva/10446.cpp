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
const int inf=2000000000;
long dp[61][61];
ubig find(long n,long back)
{
    if(n<=1)
        return 1;
    if(dp[n][back])
        return dp[n][back];
    dp[n][back]=1;
    long i;
    for(i=1;i<=back;i++)
        dp[n][back]+=find(n-i,back);
    return dp[n][back];
}
int main()
{
    long n,back,c=1;
    while(scanf("%ld %ld",&n,&back))
    {
        if(n>60)
            break;
        printf("Case %ld: %llu\n",c++,find(n,back));
    }
    return 0;
}
