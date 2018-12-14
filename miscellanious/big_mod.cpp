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
const int inf=2000000000;
ubig pwr(ubig n,ubig b)
{
     ubig res=1;
     while(b)
     {
         if(b%2)
         {
             res*=n;
             res%=mod;
         }
         b/=2;
         n*=n;
         n%=mod;
     }
     return res;
         
}
ubig power(ubig n,ubig p)
{
    if(p==0)
        return 1;
    if(p%2)
        return (n*power(n,p-1))%mod;
    ubig res=power(n,p/2);
    return (res*res)%mod;
}
int main()
{
    ubig n,p;
    while(scanf("%llu %llu",&n,&p)==2)
    {
        printf("%llu\n%llu\n",power(n,p),pwr(n,p));
    }
    return 0;
}
