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
#define ff first
#define ss second
#define pii pair<int,int>
#define psi pair<string,int>
#define eps 1e-11
#define mod 100000007
const int inf=2000000000;
int pr[1000000];
bool flag[1000000];
void sieve(int n)
{
     int m=(int)sqrt(n);
     int c=1,i,j;
     for(i=3;i<=m;i+=2)
     {
         if(flag[i]==0)
         {
             pr[c++]=i;
             for(j=i*i;j<=n;j+=i+i)
                 flag[j]=1;
         }
     }
     for(;i<=n;i+=2)
      if(flag[i]==0)
        pr[c++]=i;
        for(i=1;i<=20;i++)
        printf("%d\n",pr[i]);
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int cas,m,n,i,sq;
    bool f;
    sieve((int)sqrt(1000000000)+100);
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d %d",&m,&n);
        if(m==2)
            printf("2\n");
        else if(m==1)
            m+=2;
        else if(m%2==0)
            m++;
        for(;m<=n;m+=2)
        {
             sq=(int)sqrt(m);
             f=1;
             for(i=1;pr[i]<=sq;i++)
             {
                 if(m%pr[i]==0)
                 {
                     f=0;
                     break;
                 }
             }
             if(f)
                 printf("%d\n",m);
        }
        if(cas)
            printf("\n");
                 
    }
    return 0;
}
