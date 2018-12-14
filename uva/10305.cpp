#include<stdio.h>
long order[105],c,vis[105];
struct{
	int a[105],size;
}node[105];
int dfs(long n);
int main()
{
	long n,m,i,j,indeg[101];
	while(scanf("%ld %ld",&n,&m) &&n!=0)
	{
		for(i=1;i<=n;i++)
		{
			vis[i]=0;
			node[i].size=0;
			indeg[i]=0;
		}
		while(m--)
		{
			scanf("%ld %ld",&i,&j);
			node[i].a[node[i].size++]=j;
			indeg[j]++;
		}
		c=0;
		for(i=1;i<=n;i++)
		{
			if(indeg[i]==0)
			{
				dfs(i);
			}
		}
		c--;
		for(i=c;i>0;i--)
		{
			printf("%ld ",order[i]);
		}
		printf("%ld\n",order[0]);
	}
	return 0;
}
int dfs(long n)
{
	int i,m;
	vis[n]=1;
	for(i=0;i<node[n].size;i++)
	{
		m=node[n].a[i];
		if(vis[m]==0)
			dfs(m);
	}
	order[c++]=n;
	return 0;
}