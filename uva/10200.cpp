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
long p[10005],q[10005];
void sieve()
{
    long i,j;
    p[2]=1;
    for(i=4;i<10001;i+=2)
        p[i]=0;
    for(i=3;i<10001;i+=2)
        p[i]=1;
    for(i=3;i<=100;i+=2)
    {
        if(p[i])
        {
            for(j=i*i;j<=10000;j+=i+i)
                p[j]=0;
        }
    }
    for(i=0;i<40;i++)
        q[i*i+i+41]=1;
    for(i=3;i<10001;i++)
    {
        p[i]+=p[i-1],q[i]+=q[i-1];
    }
}                       
int main()
{
    long a,b;
    sieve();
    while(scanf("%ld %ld",&a,&b)==2)
    {
        printf("%ld %ld\n",p[b]-p[a],q[b]-q[a]);
        printf("%.2lf\n",((double)(q[b]-q[a])/(p[b]-p[a]))*100);
    }
    return 0;
}
