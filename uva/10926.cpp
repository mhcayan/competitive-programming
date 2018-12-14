#include<stdio.h>
int dfs(int n);
long d,vis[105];
struct{
	int a[105],size;
}node[105];
int main()
{
	long n,i,j,max,md,t,indeg[105];
	while(scanf("%ld",&n) && n!=0)
	{
		for(i=1;i<=n;i++)
		{
			node[i].size=0;
			vis[i]=0;
			indeg[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&t);
			while(t--)
			{
				scanf("%ld",&j);
				node[i].a[node[i].size++]=j;
				indeg[j]++;
			}
		}
		max=-1;
		for(i=1;i<=n;i++)
		{
			if(indeg[i]==0)
			{
				dfs(i);
				if(d>max)
				{
					max=d;
					md=i;
				}
				d=0;
			}
		}
		printf("%ld\n",md);
	}
	return 0;
}
int dfs(int n)
{
	int i,m;
	vis[n]=1;
	for(i=0;i<node[n].size;i++)
	{
		m=node[n].a[i];
		if(vis[m]=0)
			dfs(m);
	}
	d++;
	return 0;
}