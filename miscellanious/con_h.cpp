#include<stdio.h>
#include<stdlib.h>
int par[500];
typedef struct{
	int a,b,c;
}tag;
typedef struct{
	int adj[500],size;
}graph;
int cmp(const void *p,const void *q)
{
	tag *x=(tag *)p;
	tag *y=(tag *)q;
	return x->c-y->c;
}
int find(int r)
{
	if(par[r]==r)
		return r;
	return par[r]=find(par[r]);
}
int main()
{
	int n,e,i,x,y,z,f,status[500],total,u,v,t,front,rear,s,queue[80000];
	tag node[15000];
	graph g[250];
	while(scanf("%d",&n) && n)
	{
		for(i=1;i<=n;i++)
		{
			g[i].size=0;
			par[i]=i;
			status[i]=0;
		}
		scanf("%d",&e);
		f=0;
		for(i=0;i<e;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			    node[i].a=x;
			    node[i].b=y;
			    node[i].c=z;
				g[x].adj[g[x].size++]=y;
				g[y].adj[g[y].size++]=x;
		}
		front=rear=1;
		queue[front]=1;
		status[1]=1;
		while(front<=rear)
		{
			s=queue[front++];
			for(i=0;i<g[s].size;i++)
			{
				t=g[s].adj[i];
				if(status[t]==0)
				{
					status[t]=-status[s];
					queue[++rear]=t;
				}
				else if(status[t]==status[s])
				{
					f=1;
					break;
				}
				
			}
			if(f)
				break;
		}
		if(f)
			printf("invalid\n");
		else
		{
		    qsort(node,e,sizeof(tag),cmp);
			total=0;
			for(i=0;i<e;i++)
			{
				x=node[i].a;
				y=node[i].b;
				u=find(x);
				v=find(y);
				if(u!=v)
				{
					total+=node[i].c;
					par[u]=v;
				}
				else
				{
					if(node[i].c<0)
						total+=node[i].c;
				}
			}
			printf("%d\n",total);
		}
	}
	return 0;
}

