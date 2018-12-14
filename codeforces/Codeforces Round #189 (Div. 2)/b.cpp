#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
vector<int>edge[105];
bool vis[105];
int bfs(int s,int d)
{
	int u,v,i;
	vis[s]=1;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(i=0;i<edge[u].size();i++)
		{
			v=edge[u][i];
			if(v==d)
			    return 1;
			if(vis[v]==0)
			{
				vis[v]=1;
				q.push(v);
			}
		}
	}
	return 0;
}
int main()
{
	int cas,tc,q,b,e,x[105],y[105],node=0,i;
	scanf("%d",&cas);
	for(tc=1;tc<=cas;tc++)
	{
		scanf("%d %d %d",&q,&b,&e);
		if(q==1)
		{
			node++;
			x[node]=b,y[node]=e;
			for(i=1;i<node;i++)
			{
				if((x[i]<x[node] && x[node]<y[i]) || (x[i]<y[node] && y[node]<y[i]))
			    {
			    	edge[node].push_back(i);
			    }
			    if((x[node]<x[i] && x[i]<y[node]) || (x[node]<y[i] && y[i]<y[node]))
			        edge[i].push_back(node);
			   
			
			}
		}
		else
		{
			memset(vis,0,sizeof(vis));
			if(bfs(b,e))
			    printf("YES\n");
			else
			    printf("NO\n");
		}
	}
}
