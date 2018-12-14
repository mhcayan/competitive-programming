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
int a[505][505],pr[50000],C,dis[100105];
bool flag [100100];
void sieve()
{
     int n=100100,m,i,j;
     m=(int)sqrt(n);
     pr[0]=-1;
     pr[1]=2;
     C=2;
     for(i=3;i<=m;i+=2)
     {
         if(flag[i]==0)
         {
             pr[C++]=i;
             for(j=i*i;j<=n;j+=i+i)
                 flag[j]=1;
         }
     }
     for(;i<=n;i+=2)
     if(flag[i]==0)
         pr[C++]=i;
     for(i=1;i<C;i++)
     {
         j=pr[i]-1;
         while(j>pr[i-1])
         {
             dis[j]=pr[i]-j;
             j--;
         }
     }
}
     
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    sieve();
    int r,c,cost,ans,i,j;
    while(scanf("%d %d",&r,&c)==2)
    {
        ans=inf;
        for(i=1;i<=r;i++)
        {
                         cost=0;
            for(j=1;j<=c;j++)
            {
                scanf("%d",&a[i][j]);
                cost+=dis[a[i][j]];
            }
            if(cost<ans)
            ans=cost;
        }
        if(ans!=0)
        {
                   
                     for(i=1;i<=c;i++)
        {
                     cost=0;
            for(j=1;j<=r;j++)
            {
                //scanf("%d",&a[j][i])
                cost+=dis[a[j][i]];
            }
            if(cost<ans)
            ans=cost;
        }
        }
        printf("%d\n",ans);
            
            
    }
    return 0;
}
