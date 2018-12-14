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
int main()
{
    int tc,i,n,mx,h[2555],dp[2555],ans,k;
    set<int>ss;
    set<int>::iterator it;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        mx=-inf;
        for(i=0;i<n;i++)
        {
            scanf("%d",&h[i]);
            h[i]*=2;
            mx=max(h[i],mx);
        }
        ss.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d",&k);
            ss.insert(k);
        }
        //cout<<ss.size()<<endl;
        dp[0]=0;
        for(i=1;i<=mx;i++)
           dp[i]=inf;
        for(i=1;i<=mx;i++)
        {
            for(it=ss.begin(); it!=ss.end()&& *it<=i;it++)
            {
                if(dp[i-*it]+1<dp[i])
                     dp[i]=dp[i-*it]+1;
            }
        }
        ans=0;
        for(i=0;i<n;i++)
        {
            ans+=dp[h[i]];
        }
        printf("%d\n",ans);
    }
    return 0;
}
