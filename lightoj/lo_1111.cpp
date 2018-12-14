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
vector<int>edge[1005];
int vis[1005][1005];
void bfs(int s)
{
	int u,v,i;
	queue<int>q;
	vis[s][s]=1;
	q.push(s);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(i=0;i<edge[u].size();i++)
		{
			v=edge[u][i];
		    if(!vis[s][v])
			{
			    vis[s][v]=1;
			    q.push(v);
			}
		}
	}
}
int main()
{
	int cas,t,k,n,m,i,j,u,v,p[105],count;
	scanf("%d",&cas);
	for(t=1;t<=cas;t++)
    {
		scanf("%d %d %d",&k,&n,&m);
		//CLR(vis);
		for(i=1;i<=k;i++)
			scanf("%d",&p[i]);
		while(m--)
		{
			scanf("%d %d",&u,&v);
			edge[u].pb(v);
		}
		for(i=1;i<=k;i++)
		{
			bfs(p[i]);
		}
		count=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=k;j++)
			{
				if(!vis[p[j]][i])
					break;
			}
			if(j>k)
				count++;
		}
		printf("Case %d: %d\n",t,count);
		if(t<cas)
		{
			for(i=1;i<=n;i++)
			{
				edge[i].clear();
				for(j=1;j<=n;j++)
					vis[i][j]=0;
			}
		}

    }
    return 0;
}
