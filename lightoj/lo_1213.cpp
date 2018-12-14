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
#define ulong unsigned long
#define big long long
#define ubig unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
#define mod 100000007
const int inf=2000000000;
long M;
inline big power(big n,big k)
{
   big res=1;
   while(k)
   {
       if(k&1)
           res=(res*n)%M;
       k>>=1;
       n=(n*n)%M;
   }
   return res;
}
int main()
{
    long v,i,t,cas;
    big n,k,sum;
    scanf("%ld",&cas);
    for(t=1;t<=cas;t++)
    {
        scanf("%lld %lld %ld",&n,&k,&M);
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%ld",&v);
            sum+=v;
            if(sum>=M)
                sum%=M;
        }
        sum=(sum*(k%M))%M;
        sum=(sum*power(n,k-1))%M;
        printf("Case %ld: %lld\n",t,sum);
    }
    return 0;
}
