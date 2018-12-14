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
    int n,e,u,v,c,i,j,k,a[103][103],s,d,t,tc=1;
    while(scanf("%d %d",&n,&e) && n && e)
    {
        while(e--)
        {
            scanf("%d %d %d",&u,&v,&c);
            a[u][v]=c;
            a[v][u]=c;
        }
        scanf("%d %d %d",&s,&d,&t);
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    a[i][j]=max(a[i][j],min(a[i][k],a[k][j]));
        printf("Scenario #%d\nMinimum Number of Trips = %.0lf\n\n",tc++,ceil(double(t)/(a[s][d]-1)));
    }
    return 0;
}
