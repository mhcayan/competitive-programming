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
bool vis[101];
vector<int>edge[101];
vector<int>cost[101];
int bfs()
{
	int v,i,u,c1=0,c2=0;
	queue<int>q;
	q.push(1);
	vis[1]=1;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(i=0;i<2;i++)
		{
			v=edge[u][i];
			if(v<0)
			{
				if(!vis[-v])
				{
				    v=-v;
				    c1+=cost[u][i];
				    vis[v]=1;
				    q.push(v);
				    break;
				}
			}
			else if(!vis[v])
			{
				c2+=cost[u][i];
				vis[v]=1;
				q.push(v);
				break;
			}
		}
	}
	for(i=0;i<2;i++)
	{
		if(edge[u][i]==1)
		{
			c2+=cost[u][i];
			break;
		}
		else if(edge[u][i]==-1)
		{
			c1+=cost[u][i];
			break;
		}
	}
	return c1<c2?c1:c2;
}

int main()
{
	int cas,tc,i,n,u,v,c;
	scanf("%d",&cas);
	for(tc=1;tc<=cas;tc++)
    {
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d",&u,&v,&c);
			edge[u].pb(v);
			edge[v].pb(-u);
			cost[u].pb(c);
			cost[v].pb(c);
			
		}
		vis[n]=0;
		printf("Case %d: %d\n",tc,bfs());
		for(i=1;i<=n;i++)
		{
			edge[i].clear();
			cost[i].clear();
			vis[i]=0;
		}
    }
    return 0;
}
