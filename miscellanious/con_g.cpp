#include<stdio.h>
long long squre(long long a)
{
     return (a*a)%1000000007;
}
long long bigmod(long long b,long long p,long long m)
{
     if(p==0)
     return 1;
     else if(p%2==0)
     return squre(bigmod(b,p/2,m)%m)%m;
     else
     return ((b%m)*bigmod(b,p-1,m)%m)%m;
}
int main()
{
    long long cas,t,n,res;
    scanf("%lld",&cas);
    for(t=1;t<=cas;t++)
    {
        scanf("%lld",&n);
        res=bigmod(2,n-1,1000000007);
        printf("Case %lld: %lld\n",t,((n%1000000007)*res)%1000000007);
    }
    return 0;
}
        
