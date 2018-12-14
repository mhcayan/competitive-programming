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
#define M 1000000000000LL
const int inf=2000000000;
big a[80200],d=0;
bool flag[1000052];
//long d=0;
long sieve()
{
     big i,j,p;
     p=4;
     while(p<=M)
     {
         a[d++]=p;
         p=p*2;
     }
     for(i=3;i<=1000;i+=2)
     {
         if(!flag[i])
         {
             p=i*i;
             while(p<=M)
             {
                 a[d++]=p;
                 p=p*i;
             }
             for(j=i*i;j<=1000050;j+=i+i)
                 flag[j]=1;
         }
     }
     for(;i<=1000050;i+=2)
     {
         if(!flag[i])
         {
             p=i*i;
             if(p>M)
                 break;
             while(p<=M)
             {
                 a[d++]=p;
                 p=p*i;
             }
         }
     }
     sort(a,a+d);
     return 0;
}
int main()
{
    big tc,m,b,e,l,i;
    big low,high;
    sieve();
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld %lld",&low,&high);
        b=0,e=d-1;
        while(b<=e)
        {
            m=(b+e)/2;
            if(low<=a[m])
                e=m-1;
            else
                b=m+1;
        }
        l=b;
        e=d-1;
        while(b<=e)
        {
            m=(b+e)/2;
            if(high<a[m])
                e=m-1;
            else
                b=m+1;
        }
        printf("%lld\n",e-l+1);
    }
    return 0;
}
