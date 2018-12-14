#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
using namespace std;
vector<int>edge[105];
void bfs(int s,int dis[])
{
	int i,u,v;
	queue<int>q;
	bool vis[105];
	CLR(vis);
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(i=0;i<edge[u].size();i++)
		{
			v=edge[u][i];
			if(vis[v]==0)
			{
				q.push(v);
				dis[v]=1+dis[u];
				vis[v]=1;
			}
		}
	}
}
int main()
{
	int t,cas,i,e,v,dis1[105],dis2[105],max,s,d,p,q;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
	{
		scanf("%d %d",&v,&e);
		for(i=0;i<e;i++)
		{
			scanf("%d %d",&p,&q);
			edge[p].pb(q);
			edge[q].pb(p);
		}
	
		scanf("%d %d",&s,&d);
		bfs(s,dis1);
		bfs(d,dis2);
		max=0;
	    for(i=0;i<v;i++)
		{
			edge[i].clear();
	    	if(dis1[i]+dis2[i]>max)
			   max=dis1[i]+dis2[i];
		}
		printf("Case %d: %d\n",t,max);
	}
	return 0;
}
	
			
