#include<stdio.h>
int init(int v);
int indeg[100],outdeg[100];
int parent[101][101],dist[101][101],pos[1000];
struct tag
{
	int a[100];
	int size;
	int status;
	int parent;
	int dis;
}node[100];
int main()
{
	int f1,l,q_no,qre,t,c;
	int v,e,i,front,rear,p,q,n,queue[1000],s,d;
	scanf("%ld",&t);
	c=1;
	while(c<=t)
	{
		scanf("%ld %ld",&v,&e);
		for(i=1;i<=v;i++)
		{
			node[i].size=0;
			indeg[i]=0;
			outdeg[i]=0;
			node[i].pos=0;
		}
	    for(i=0;i<e;i++)
		{
			scanf("%ld %ld",&p,&q);
		    node[p].a[node[p].size++]=q;
		    indeg[q]++;
		    outdeg[p]++;
		    node[q].parent=p;
		}
		scanf("%ld",&s);
	    scanf("%ld",&qre);
		while(qre--)
		{
			scanf("%ld",&q_no);
			init(v);
			if(q_no==1)
			{
				scanf("%ld",&d);
			    front=rear=1;
	            queue[rear]=s;
	            node[s].status=2;
	            node[s].dis=0;
				if(s==d)
				{
					printf("0\n");
				}
				else
				{
					while(front<=rear)
					{
						n=queue[front];
		                front++;
		                for(i=0;i<node[n].size;i++)
						{
							if(node[node[n].a[i]].status==1)
							{
								rear++;
				                queue[rear]=node[n].a[i];
				                node[node[n].a[i]].status=2;
				                node[node[n].a[i]].parent=n;
				                node[node[n].a[i]].dis=1+node[n].dis;
				                if(queue[rear]==d)
									break;
							}
						}
					    if(queue[rear]==d)
							break;
					}
				    if(queue[rear]==d && node[d].dis<99999)
						printf("%ld\n",node[d].dis);
				    else
						printf("-1\n");
				}
			}
			else if(q_no==2)
			{
				front=rear=1;
				queue[front]=s;
				node[s].status=2;
				while(front<=rear)
				{
					n=queue[front++];
					for(i=0;i<node[n].size;i++)
					{
						if(node[node[n].a[i]].status==1)
						{
							queue[++rear]=node[n].a[i];
							node[node[n].a[i]].status=2;
						}
					}
				}
				if(rear==v)
				{
					int flag=0;
					for(i=1;i<=v;i++)
					{
						if(indeg[i]!=outdeg[i])
						{
							flag=1;
							break;
						}
					}
					if(flag)
						printf("No\n");
					else
						printf("Yes\n");
				}
				else
					printf("No\n");

			}
			else if(q_no==3)
			{
				int stat[1000]={0};
				par[1000][1000];
				front=rear=1;
				queue[front]=s;
				stat[s]=1;
				while(front<=rear)
				{
					n=queue[front];
					for(i=0;i<=node[n].size;i++)
					{


			}
		}
	}
	return 0;
}
int init(int v)
{
	int i;
	for(i=1;i<=v;i++)
	{
		node[i].status=1;
	    node[i].dis=99999;
	    node[i].parent=0;
	}
	return 0;
}

