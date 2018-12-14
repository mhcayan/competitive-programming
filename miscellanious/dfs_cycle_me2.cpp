//cycle finding using dfs
#include<stdio.h>
#include<string.h>
int dfs(long);
struct{
	long a[100],size;
}node[100];
long flag,vis[1000];
int main()
{
	long v,e,p,q,i,s;
	while(scanf("%ld %ld",&v,&e)==2)
	{
		flag=0;
		memset(vis,0,sizeof(vis));
		for(i=0;i<=v;i++)
			node[i].size=0;
		for(i=0;i<e;i++)
		{
			scanf("%ld %ld",&p,&q);
			node[p].a[node[p].size++]=q;
		}
		scanf("%ld",&s);//source
		if(dfs(s))
			printf("cycle found\n");
		else
			printf("no cycle\n");
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
		{
			dfs(n);
		}
		else
		{
			flag=1;
			return 1;
		}
		if(flag)
			return 1;
	}
	vis[s]=0;
	return 0;
}



