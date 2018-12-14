#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INFINITY 9999;
int bfs(int s,int v);
int dis[100];
queue<int>q;
vector<int>adj[100],cost[100];
int main()
{
	int v,e,c,s,d,i,a,b;
	cin>>v>>e;
	for(i=0;i<e;i++)
	{
		cin>>a>>b>>c;
		adj[a].push_back(b);
		adj[b].push_back(a);
		cost[a].push_back(c);
		cost[b].push_back(c);
	}
	cin>>s>>d;
	bfs(s,v);
	for(i=0;i<v;i++)
        cout<<dis[i]<<' ';
	//cout<<dis[d]<<endl;
    for(i=0;i<v;i++)
	{
		cost[i].clear();
		adj[i].clear();
	}
	return 0;
}
int bfs(int s,int v)
{
	int i,n,t;
	for(i=0;i<v;i++)
		dis[i]=INFINITY;
	q.push(s);
	dis[s]=0;
	while(!q.empty())
	{
		n=q.front();
		q.pop();
		for(i=0;i<adj[n].size();i++)
		{
			t=adj[n][i];
			if(dis[t]>dis[n]+cost[n][i])
			{
				dis[t]=dis[n]+cost[n][i];
				q.push(t);
			}
		}
	}
	return 0;
}

