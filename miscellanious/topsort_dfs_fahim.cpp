#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
const int inf=2000000000;
int vis[500],invalid;
vector<int>edge[500],list;
void take(int u)
{
	if(vis[u]==2 || invalid)
		return;
	if(vis[u]==1)
	{
		invalid=1;
		return;
	}
	vis[u]=1;
	for(int i=0;i<edge[u].size();i++)
		take(edge[u][i]);
	vis[u]=2;
	list.pb(u);
}
int main()
{
	int n,e,i,u,v;
    while(scanf("%d %d",&n,&e)==2)
    {
		CLR(vis);
		while(e--)
		{
			scanf("%d %d",&u,&v);
			edge[v].pb(u);
		}
		invalid=0;
		for(i=1;i<=n;i++)
			take(i);
		if(invalid)
			printf("invalid\n");
		else
		{
		    for(i=0;i<list.size();i++)
			    printf("%d ",list[i]);
			printf("\n");
		}
    }
    return 0;
}
