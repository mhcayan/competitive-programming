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
struct data{
       int node,pigeon;
};
data dd;
bool vis[10005];
int tim,d[10005],low[10005],par[10005],root,ar[10005],cnt;
vector<int>edge[10005];
vector<data>art;
void dfs2(int u)
{
     int i,v;
     vis[u]=1;
     d[u]=tim;
     low[u]=tim++;
     for(i=0;i<edge[u].size();i++)
     {
         v=edge[u][i];
         if(vis[v]==0)
         {
             par[v]=u;
             if(u==root)
                 cnt++;
             dfs2(v);
             if(low[v]>=d[u] && u!=root)
                 ar[u]++;
             if(low[v]<low[u])
                 low[u]=low[v];
         }
         else if(d[v]<low[u])
             low[u]=d[v];
     }
     tim++;
}    
void init(int n)
{
     int i;
     for(i=0;i<n;i++)
     {
         edge[i].clear();
         vis[i]=0;
         par[i]=-1;
         ar[i]=0;
     }
     art.clear();
}     
bool cmp(data a,data b)
{
     if(a.pigeon==b.pigeon)
         return a.node<b.node;
     else
         return a.pigeon>b.pigeon;
}
int main()
{
    int n,m,u,v,i,com;
    while(scanf("%d %d",&n,&m) && n)
    {
        init(n);
        while(scanf("%d %d",&u,&v) && u!=-1 && v!=-1)
        {
            edge[u].pb(v);
            edge[v].pb(u);
        }
        com=0;
        tim=1;
        for(i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                cnt=0;
                com++;
                root=i;
                dfs2(i);
                ar[i]=cnt-1;
            }
        }
        for(i=0;i<n;i++)
        {
            dd.node=i;
            dd.pigeon=ar[i]+com;
            art.pb(dd);
        }
        sort(art.begin(),art.end(),cmp);
   //cout<<art.size()<<endl;
        for(i=0;i<m;i++)
            printf("%d %d\n",art[i].node,art[i].pigeon);
        printf("\n");
                
            
    }
    return 0;
}
