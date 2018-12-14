//finding articulation point
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
vector<int>edge[1000];
int vis[1000],deg[1000],d[1000],f[1000],low[1000],time,ap[1000],size,flag[1000];
void art(int u)
{
	vis[u]=1;
	d[u]=++time;
	low[u]=time;
	int i,v;
	for(i=0;i<edge[u].size();i++)
	{
		v=edge[u][i];
		if(vis[v]==0)
		{
			deg[u]++;         //deg is calculated for the root node
			art(v);
			if(low[v]>=d[u] && flag[u]==0)  
			{
				flag[u]=1;
				ap[++size]=u;
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
	f[u]=++time;
}
int main()
{
	int i,n,e,u,v;
	while(scanf("%d %d",&n,&e)==2)
	{
		time=0;

		ap[0]=-999;
		size=0;
		for(i=1;i<=n;i++)
		{
			edge[i].clear();
			deg[i]=0;
			vis[i]=0;
			flag[i]=0;
		}
		while(e--)
		{
			scanf("%d %d",&u,&v);
			edge[u].pb(v);
			edge[v].pb(u);
		}
		for(i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				art(i);
				if(ap[size]==i && deg[i]<=1)  //if deg of root<=1,then it is not articulation point
					size--;
			}
		}
		for(i=1;i<=size;i++)     
			printf("%d ",ap[i]);       //printing articulation point
		printf("\n");

	}
	return 0;
}
