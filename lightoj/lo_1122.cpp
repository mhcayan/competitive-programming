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
int dp[12][12],d,n,a[12]; 
int find(int p,int k)
{
    if(k==d)
        return 1;
    int &it=dp[p][k];
    if(it!=-1)
        return it;
    it=0;
    int i;
    for(i=0;i<n;i++)
    {
       if(a[i]<p)
       {
           if(p-a[i]>2)
              continue;
           it+=find(a[i],k+1);
       }
       else
       {
           if(a[i]-p>2)
               break;
           it+=find(a[i],k+1);
       }
    }
    return it;
}
       
int main()
{
    int cas,t,i,ans;
    scanf("%d",&cas);
    for(t=1;t<=cas;t++)
    {
        scanf("%d %d",&n,&d);
        SET(dp);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        ans=0;
        for(i=0;i<n;i++)
            ans+=find(a[i],1);
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
