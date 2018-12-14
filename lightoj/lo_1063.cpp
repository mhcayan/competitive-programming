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
#include<map>
#include<iterator>
using namespace std;
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
const int inf=2000000000;
vector<int>edge[10005];
bool flag[10005],vis[10005];
int ap,d[10005],tt,low[10005],deg;
void art(int u)
{
	vis[u]=1;
	d[u]=++tt;
	low[u]=tt;
	int i,v;
	for(i=0;i<edge[u].size();i++)
	{
		v=edge[u][i];
		if(vis[v]==0)
		{
			if(u==1)
				deg++;
			art(v);
			if(low[v]>=d[u] && flag[u]==0)
			{
				flag[u]=1;
				ap++;
			}
			if(low[v]<low[u])
				low[u]=low[v];
		}
		else
		{
			if(d[v]<low[u])
				low[u]=d[v];
		}
	}
	++tt;
}
int main()
{
	int cas,t,n,m,u,v;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
    {
		scanf("%d %d",&n,&m);
		if(t>1)
		{
			ap=0;
			tt=0;
			deg=0;
			for(u=1;u<=n;u++)
			{
				flag[u]=0;
				vis[u]=0;
				edge[u].clear();
			}
		}
		while(m--)
		{
			scanf("%d %d",&u,&v);
			edge[u].pb(v);
			edge[v].pb(u);
		}
		art(1);
		if(flag[1] && deg<=1)
			ap--;
		printf("Case %d: %d\n",t,ap);
    }
    return 0;
}
