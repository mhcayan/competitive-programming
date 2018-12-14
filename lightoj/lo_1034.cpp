#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
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
vector<int>edge[10010];
bool vis[10010],flag[10010];
int list[10010],c;
void dfs1(int u)
{
	int i,v;
	vis[u]=1;
	for(i=0;i<edge[u].size();i++)
	{
		v=edge[u][i];
		if(!vis[v])
			dfs1(v);
	}
	list[++c]=u;
}
void dfs2(int u)
{
	int i,v;
	flag[u]=1;
	for(i=0;i<edge[u].size();i++)
	{
		v=edge[u][i];
		if(!flag[v])
			dfs2(v);
	}
}
/*void bfs(int u)
{
	int i,v;
	queue<int>q;
	q.push(u);
	flag[u]=1;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(i=0;i<edge[u].size();i++)
		{
			v=edge[u][i];
			if(!flag[v])
			{
				flag[v]=1;
				q.push(v);
			}
		}
	}
}*/
int main()
{
	int cas,t,n,m,i,a,b;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
    {
		scanf("%d %d",&n,&m);
		while(m--)
		{
			scanf("%d %d",&a,&b);
			edge[a].pb(b);
		}
		for(i=1;i<=n;i++)
		{
			if(!vis[i])
		        dfs1(i);
		}
		int count=0;
		for(i=n;i>0;i--)
		{
			if(flag[list[i]]==0)
			{
				count++;
				dfs2(list[i]);
			}
		}
		printf("Case %d: %d\n",t,count);
		if(t<cas)
		{
			c=0;
		    for(i=1;i<=n;i++)
			{
			    edge[i].clear();
			    vis[i]=0;
			    flag[i]=0;
			}
		}
    }
    return 0;
}
