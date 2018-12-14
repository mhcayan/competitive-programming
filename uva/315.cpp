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
#include<set>
#include<sstream>
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
bool vis[105],ar[105];
int low[105],par[105],art,tim,d[105],root,cnt;
vector<int>edge[105];
void dfs(int u)
{
	vis[u]=1;
	d[u]=tim;
	low[u]=tim++;
	int i,v;
	for(i=0;i<edge[u].size();i++)
	{
		v=edge[u][i];
		if(vis[v]==0)
		{
			if(u==root)
				cnt++;
			par[v]=u;
			dfs(v);
			if(low[v]>=d[u] && ar[u]==0)
			{
				ar[u]=1;
				art++;
			}
			if(low[v]<low[u])
				low[u]=low[v];
		}
		else if(v!=par[u] && d[v]<low[u])
			low[u]=d[v];
	}
	tim++;
}
int main()
{
	int n,i,u,v;
	char line[1005];
	while(scanf("%d",&n) && n)
    {
		for(i=1;i<=n;i++)
		{
			par[i]=-1;
			vis[i]=0;
			ar[i]=0;
			edge[i].clear();
		}
		art=0;
		getchar();
		while(gets(line) && line[0]!='0')
		{
			stringstream ss(line);
			ss>>u;
			while(ss>>v)
			{
				edge[u].pb(v);
				edge[v].pb(u);
			}
		}
		tim=1;
		for(i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				root=i;
				ar[i]=1;
				cnt=0;
				dfs(i);
				if(cnt>1)
					art++;
			}
		}
		printf("%d\n",art);
    }
    return 0;
}
