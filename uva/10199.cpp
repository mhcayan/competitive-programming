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
bool vis[105],ar[105];
int par[105],low[105],d[105],tim,root,cnt;
vector<string>ct;
vector<string>art;
vector<int>edge[105];
map<string,int>mp;
void dfs(int u)
{
     vis[u]=1;
     low[u]=tim;
     d[u]=tim++;
     int i,v;
     for(i=0;i<edge[u].size();i++)
     {
         v=edge[u][i];
         if(vis[v]==0)
         {
             if(u==root)
                 cnt++;   
             par[v]=u;
             dfs(v);
             if(low[v]>=d[u] && ar[u]==0)
             {
                 ar[u]=1;
                 art.pb(ct[u]);
             }
             if(low[v]<low[u])
                 low[u]=low[v];
         }
         else if(par[u]!=v)
         {
              if(low[u]>d[v])
                  low[u]=d[v];
         }
     }
     tim++;
}
int main()
{ 
    int n,i,u,v,e,tc=1;
    string c1,c2;
    while(scanf("%d",&n) && n)
    {
         ct.pb("goru");
         for(i=1;i<=n;i++) 
         {
             cin>>c1;
             ct.pb(c1);
             mp[c1]=i;
             ar[i]=0;
             vis[i]=0;
             par[i]=-1;
             edge[i].clear();
         }
         tim=1;
         //mp.clear();
         //ct.clear();
         art.clear();
         scanf("%d",&e);
         while(e--)
         {
             cin>>c1>>c2;
             u=mp[c1];
             v=mp[c2];
             edge[u].pb(v);
             edge[v].pb(u);
         }
         for(i=1;i<=n;i++)
         {
             if(vis[i]==0)
             {
                 cnt=0;
                 ar[i]=1;
                 root=i;
                 dfs(i);
                 if(cnt>1)
                     art.pb(ct[i]);
             }
         }
         sort(art.begin(),art.end());
         printf("City map #%d: %d camera(s) found\n",tc++,art.size());
         for(i=0;i<art.size();i++)
             cout<<art[i]<<endl;
         printf("\n");
         mp.clear();
         ct.clear();
    }
    return 0;
}
