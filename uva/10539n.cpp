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
long pr[80000],c=1;
bool flag[1000000];
long sieve()
{
     long i,j;
     pr[0]=2;
     for(i=3;i<=1000;i+=2)
     {
         if(!flag[i])
         {
             pr[c++]=i;
             for(j=i*i;j<=1000050;j+=i+i)
                 flag[j]=1;
         }
     }
     for(;i<=1000050;i+=2)
     {
         if(!flag[i])
             pr[c++]=i;
     }
     return 0;
}             
int main()
{
    big p,low,high,sq,count;
    long tc,i;
    sieve();
    scanf("%ld",&tc);
    while(tc--)
    {
        scanf("%lld %lld",&low,&high);
        count=0;
        sq=sqrt(high);
        for(i=0;pr[i]<=sq;i++)
        { 
            count+=floor(log(high)/log(pr[i]))-ceil(log(low)/log(pr[i]))+1;
            if(low==1)
                count--;
            if(pr[i]>=low)
                count--;
        }
        printf("%lld\n",count);          
    }
    return 0;
}



