#include<stdio.h>
#include<string.h>
long status[1000],par[1000],parent[1000],indeg[1000],outdeg[1000],dis[1000];
struct tag
{
	int a[1000];
	int size;
}node[100];
int main() 
{
	long c,t,v,e,n1,n2,s,d,nq,qr,q,front,rear,n,flag,i,queue[1000];
	scanf("%ld",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%ld %ld",&v,&e);
		for(i=0;i<e;i++)
		{
			scanf("%ld %ld",&n1,&n2);
			node[n1].a[node[n1].size++]=n2;
			indeg[n2]++;
			outdeg[n1]++;
		}
		scanf("%ld",&s);
		scanf("%ld",&nq);
		printf("Case : %ld\n",t);
		for(qr=1;qr<=nq;qr++)
		{
			scanf("%ld",&q);
			if(q==1)
			{
				scanf("%ld",&d);
				memset(status,0,sizeof(status));
				front=rear=1;
				queue[front]=s;
				par[s]=-1;
				status[s]=1;
				dis[s]=0;
				flag=0;
				while(front<=rear)
				{
					n=queue[front++];
					for(i=0;i<node[n].size;i++)
					{
						if(status[node[n].a[i]]==0)
						{
							queue[++rear]=node[n].a[i];
							par[node[n].a[i]]=n;
							dis[node[n].a[i]]=1+dis[n];
							status[node[n].a[i]]=1;
							if(queue[rear]==d)
							{
								printf("%ld\n",dis[d]);
								flag=1;
								break;
							}
						}
					}
					if(flag)
						break;
				}
				if(flag==0)
					printf("-1\n");
			}
			else if(q==2)
			{
				memset(status,0,sizeof(status));
				front=rear=1;
				queue[front]=s;
				status[s]=1;
				while(front<=rear)
				{
					n=queue[front++];
					for(i=0;i<node[n].size;i++)
					{
						if(status[node[n].a[i]]==0)
						{
							queue[++rear]=node[n].a[i];
							status[node[n].a[i]]=1;
						}
					}
				}
				if(rear==v)
				{
					flag=0;
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
			else if(q==3)
			{
				memset(status,0,sizeof(status));
				scanf("%ld %ld",&len,&d);
				front=rear=1;
				queue[front]=s;
				status[s]=1;
				while(front<=rear)
				{
					n=queue[front++];
					for(i=0;i<node[n].size;i++)
					{
						queue[++rear]=node[n].a[i];
						status[node[n].a[i]]++;
						par[node[n].a[i]]=n;
						dis[nod[n].a[i]][status[node[n].a[i]]=1+dis[n][


			}
		}
	}
	return 0;
}
