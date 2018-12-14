#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define push_back pb
#define SIZE 200
const int inf=2000000000;
long count1,count2;
vector<long>edge[SIZE],cost[SIZE];
long bfs(long s,long d,long n)
{
	long dis[10000],i,u,v;
	for(i=0;i<=n;i++)
		dis[i]=inf;
	queue<long>q;
	q.push(s);
	dis[s]=0;
	while(!q.empty())
	{
		count1++;
		u=q.front();
		q.pop();
		for(i=0;i<edge[u].size();i++)
		{
			v=edge[u][i];
			if(dis[v]>dis[u]+cost[u][i])
			{
				count2++;
				dis[v]=dis[u]+cost[u][i];
				q.push(v);
			}
		}
	}
	return dis[d];
}
int main()
{
	long s,d,u,v,n,e,i,c;
	while(scanf("%ld %ld",&n,&e)==2)
	{
		count1=count2=0;
		for(i=0;i<e;i++)
		{
			scanf("%ld %ld %ld",&u,&v,&c);
			edge[u].pb(v);
			edge[v].pb(u);
			cost[u].pb(c);
			cost[v].pb(c);
		}
		scanf("%ld %ld",&s,&d);
		printf("%ld\n",bfs(s,d,n));
		printf("complexity:\n%ld %ld\n",count1,count2);
	}
	return 0;
}
			