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
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
//const int inf=2000000000;
int ans,dis[30500];
bool vis[30500];
vector<int>edge[30500],cost[30500];
void dfs(int u)
{
	vis[u]=1;
	int i,v;
	for(i=0;i<edge[u].size();i++)
	{
		v=edge[u][i];
		if(vis[v]==0)
		{
		    dis[v]=dis[u]+cost[u][i];
		    if(dis[v]>dis[ans])
		    	ans=v;
		    dfs(v);
		}
	}
}
int main()
{
	int cas,t,n,e,u,v,w,i;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
    {
		scanf("%d",&n);
		e=n-1;
		while(e--)
		{
			scanf("%d %d %d",&u,&v,&w);
			edge[u].pb(v);
			cost[u].pb(w);
			edge[v].pb(u);
			cost[v].pb(w);
		}
		ans=0;
		dis[0]=0;
		dfs(0);
		dis[ans]=0;
		CLR(vis);
		dfs(ans);
		printf("Case %d: %d\n",t,dis[ans]);
		for(i=0;i<n;i++)
		{
			vis[i]=0;
			edge[i].clear();
			cost[i].clear();
		}
	}
    return 0;
}
