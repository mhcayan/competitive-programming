#include<stdio.h>
struct tag{
	int a[25],size;
};
int main()
{
	struct tag node[25];
	int q,qr,n,nd,i,j,vis[25],dis[25],s,d,front,rear,queue[10000],t=1;
	while(scanf("%d",&n)==1)
	{
		for(i=1;i<21;i++)
		{
			node[i].size=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&nd);
			node[1].a[node[1].size++]=nd;
			node[nd].a[node[nd].size++]=1;
		}
		for(i=2;i<20;i++)
		{
			scanf("%d",&n);
			for(j=0;j<n;j++)
			{
				scanf("%d",&nd);
				node[i].a[node[i].size++]=nd;
				node[nd].a[node[nd].size++]=i;
			}
		}
		scanf("%d",&qr);
		printf("Test Set #%d\n",t++);
		for(q=1;q<=qr;q++)
		{
			for(i=1;i<21;i++)
				vis[i]=0;
		    scanf("%d %d",&s,&d);
		    front=rear=1;
		    queue[front]=s;
		    vis[s]=1;
		    dis[s]=0;
		    while(front<=rear)
			{
			    n=queue[front++];
			    for(i=0;i<node[n].size;i++)
				{
				    if(vis[node[n].a[i]]==0)
					{
					    queue[++rear]=node[n].a[i];
					    vis[node[n].a[i]]=1;
					    dis[node[n].a[i]]=1+dis[n];
					    if(queue[rear]==d)
						{
						    front=rear+1;
						    break;
						}
					}
				}
			}
		    printf("%2d to %2d: %d\n",s,d,dis[d]);
		}
		printf("\n");
	}
	return 0;
}
		
