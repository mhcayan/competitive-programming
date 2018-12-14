//counting no of cycle in a connected graph by dfs
#include<stdio.h>
int dfs(long);
long cycle,vis[100];
struct{
	long a[100],size;
}node[100];
int main()
{
	long e,v,i,p,q,s;
	while(scanf("%ld %ld",&v,&e)==2)
	{
		cycle=0;
		for(i=0;i<=v;i++)
		{
			node[i].size=0;
			vis[i]=0;
		}
		for(i=0;i<e;i++)
		{
			scanf("%ld %ld",&p,&q);
			node[p].a[node[p].size++]=q;
		}
		scanf("%ld",&s);//source
		dfs(s);
		printf("no. of cycle=%ld\n",cycle);
	}
	return 0;
}
int dfs(long s)
{
	long i,n;
	vis[s]=1;
	for(i=0;i<node[s].size;i++)
	{
		n=node[s].a[i];
		if(vis[n]==0)
			dfs(n);
		else
		{
			cycle++;
		}
	}
	vis[s]=0;
	return 0;
}
