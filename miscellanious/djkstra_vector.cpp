#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INFINITY 9999;
int dkstra(int s,int v);
int dis[100];
vector<int>adj[100];
vector<int>cost[100];
int main()
{
	int v,e,i,a,b,c,s;
	scanf("%d %d",&v,&e);
	for(i=0;i<e;i++)
	{
		cin>>a>>b>>c;
		adj[a].push_back(b);
		adj[b].push_back(a);
		cost[a].push_back(c);
		cost[b].push_back(c);
	}
	scanf("%d",&s);
	dkstra(s,v);
	for(i=0;i<v;i++)
		cout<<dis[i]<<' ';
	return 0;
}
int dkstra(int s,int v)
{
	queue<int>q;
	int i,n,t;
	for(i=0;i<v;i++)
		dis[i]=INFINITY;
	dis[s]=0;
	q.push(s);
	for(i=0;i<v;i++)
	{
		if(i!=s)
			q.push(i);
	}
	while(!q.empty())
	{
		n=q.front();
		q.pop();
		for(i=0;i<adj[n].size();i++)
		{
			t=adj[n][i];
			if(dis[t]>dis[n]+cost[n][i])
				dis[t]=dis[n]+cost[n][i];
		}
	}
	return 0;
}