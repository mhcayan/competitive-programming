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

#define sd(a) scanf("%d",&a)
//#define sd2(a,b) scanf("%d %d",&a,&b)
#define slf(a) scanf("%lf",&a)
//#define slld(a) scanf("%lld",&a)
//#define sllu(a) scanf("%llu",&a)
const int inf=2000000000;

int main()
{
    int i,j,k,n,m,f,value;
    vector<int>v[10000];
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(scanf("%d",&n)==1)
    {
        f=0;
        m=2*n;
        for(i=1;i<=5000;i++)
            v[i].clear();
         int max=-1;
        for(i=1;i<=m;i++)
        {
            scanf("%d",&value);
            v[value].pb(i);
            if(value>max)
            max=value;
        }
        for(i=1;i<=max;i++)
        {
            if(v[i].size()%2==1)
            {
               f=1;
               printf("-1\n");
               break;
            }
        }
        if(f==1)
           continue;
        for(i=1;i<=max;i++)
        {
           if(v[i].size()==0)
               continue;
           for(j=0,k=v[i].size()-1;j<k;j++,k--)
           {
               printf("%d %d\n",v[i][j],v[i][k]);
           }
        }
            
    }
    return 0;
}
