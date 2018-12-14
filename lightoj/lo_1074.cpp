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
using namespace std;
#define ulong unsigned long
#define big long long
#define ubig unsigned long long
#define pi acos(-1)
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define eps 1e-11
#define mod 100000007
const int inf=2000000000;
struct data
{
	int x,y,c;
};
data E[100000];
int dis[203],n,e;
bool flag[203];
vector<int>edge[203];
void bell()
{
	int i,u,v,j;
	dis[1]=0;
	for(i=1;i<n;i++)
	{
		edge[i].clear();
		for(j=0;j<e;j++)
		{
			u=E[j].x;
			v=E[j].y;
			if(dis[v]>dis[u]+E[j].c)
				dis[v]=dis[u]+E[j].c;
		}
	}
	edge[n].clear();
	for(i=1;i<n;i++)
	{
		if(dis[i]<3)
			flag[i]=0;
		for(j=0;j<e;j++)
		{
			u=E[j].x;
			v=E[j].y;
			if(dis[v]>dis[u]+E[j].c)
			{
				dis[v]=dis[u]+E[j].c;
				flag[v]=0;
			}
		}
	}
	if(dis[n]<3)
		flag[n]=0;
	
}
void dfs(int u)
{
	int i,v;
	flag[u]=1;
	for(i=0;i<edge[u].size();i++)
	{
		v=edge[u][i];
		if(flag[v]==0)
		    dfs(v);
	}
}
int main()
{
	int cas,tc,i,q,b[203];
	data a;
	scanf("%d",&cas);
	for(tc=1;tc<=cas;tc++)
    {
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			flag[i]=0;
			dis[i]=inf;
			scanf("%d",&b[i]);
		}
		scanf("%d",&e);
		for(i=0;i<e;i++)
		{
			scanf("%d %d",&a.x,&a.y);
			E[i].x=a.x;
			E[i].y=a.y;
			a.c=b[a.y]-b[a.x];
			a.c=a.c*a.c*a.c;
			E[i].c=a.c;
			edge[a.x].pb(a.y);
		}
		i=1;
		dfs(i);
		bell();
		scanf("%d",&q);
		printf("Case %d:\n",tc);
		while(q--)
		{
			scanf("%d",&i);
			if(flag[i])
				printf("%d\n",dis[i]);
			else
				printf("?\n");
		}
		//E.clear();
    }
    return 0;
}
