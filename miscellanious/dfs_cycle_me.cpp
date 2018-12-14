#include<stdio.h>
int dfs(long s);
struct tag{
	long a[100], size;
}node[100];
long  v,vis[1000],start[1000],end[1000],t,stack[10000],top,flag=0;
int main()
{
	long v,e,i,p,q,s;
	scanf("%ld %ld",&v,&e);
	for(i=0;i<=v;i++)
	{
		vis[i]=0;
		node[i].size=0;
	}
	for(i=0;i<e;i++)
	{
		scanf("%ld %ld",&p,&q);
		node[p].a[node[p].size++]=q;
	}
	scanf("%ld",&s);
	dfs(s);
	if(flag)
		printf("cycle\n");
	else
	{
		for(i=1;i<=v;i++)
		    printf("%ld %ld\n",start[i],end[i]);
	}
	return 0;
}
int dfs(long s)
{
	long n,i;
	vis[s]=1;
	start[s]=++t;
	stack[top++]=s;
	for(i=0;i<node[s].size;i++)
	{
		n=node[s].a[i];
		if(vis[n]==0)
			dfs(n);
		else
		{
			for(i=0;i<top;i++)
			{
				if(stack[i]==n)
				{
					flag=1;
					return 0;
				}
			}
		}
		if(flag)
			return 0;
	}
	top--;
	end[s]=++t;
	return 0;
}

	
