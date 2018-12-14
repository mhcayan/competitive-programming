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
#define pii pair<int,int>
#define ff first
#define ss second
#define eps 1e-11
#define mod 100000007
const int inf=2000000000;
bool vis[100000];
int low[100000],par[100000],d[100000],tim;
vector<pii>br;
vector<int>edge[10000];
void dfs(int u)
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
            dfs(v);
            if(low[v]>d[u])
            {
                if(u<v)
                    br.pb(pii(u,v));
                else
                    br.pb(pii(v,u));
            }
            if(low[v]<low[u])
                low[u]=low[v];
        }
        if(par[u]!=v && d[v]<low[u])
        {
            low[u]=d[v];
        }
    } 
    tim++;
}         
int main()
{
    int n,i,u,e,v;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            vis[i]=0;
            par[i]=-1;
            scanf("%d (%d)",&u,&e);
            while(e--)
            {
                scanf("%d",&v);
                edge[u].pb(v);
                edge[v].pb(u);
            }
        }
        tim=1;
        for(i=0;i<n;i++)
        {
            if(vis[i]==0)
                dfs(i);
        }   
        sort(br.begin(),br.end());
        printf("%d critical links\n",br.size());
        for(i=0;i<br.size();i++)
            printf("%d - %d\n",br[i].ff,br[i].ss);
        printf("\n");
        for(i=0;i<n;i++)  
        {
            edge[i].clear();
        }
        br.clear();
    }   
    return 0;
}
