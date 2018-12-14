#include<stdio.h>
#include<string.h>
struct tag{
	int a[100],size;
}node[35];
int main()
{
	long cas,t,i,j,front,rear,queue[10000],dis[50],vis[50],s,d,n,v,e,p,n1,n2,ship;
	char vertex[100][10],s1[4],s2[4];
	scanf("%ld",&cas);
	printf("SHIPPING ROUTES OUTPUT\n\n");
	for(t=1;t<=cas;t++)
	{  
		printf("DATA SET  %ld\n\n",t);
		scanf("%ld %ld %ld",&v,&e,&p);
		for(i=1;i<=v;i++)
			node[i].size=0;
		for(i=1;i<=v;i++)
			scanf("%s",&vertex[i]);
		for(i=1;i<=e;i++)
		{
			scanf("%s %s",&s1,&s2);
			for(j=1;j<=v;j++)
			{
				if(strcmp(s1,vertex[j])==0)
				{
					n1=j;
					break;
				}
			}
			for(j=1;j<=v;j++)
			{
				if(strcmp(s2,vertex[j])==0)
				{
					n2=j;
					break;
				}
			}
			node[n1].a[node[n1].size++]=n2;
			node[n2].a[node[n2].size++]=n1;
		}
		for(j=1;j<=p;j++)
		{
		    scanf("%ld %s %s",&ship,&s1,&s2);
		    for(i=1;i<=v;i++)
			{
			    if(strcmp(vertex[i],s1)==0)
				{
			    	s=i;
				    break;
				}
			}
		    for(i=1;i<=v;i++)
			{
			    if(strcmp(vertex[i],s2)==0)
				{
				    d=i;
			    	break;
				}
			}
		    for(i=1;i<=v;i++)
			    vis[i]=0;
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
						dis[node[n].a[i]]=1+dis[n];
					    if(queue[rear]==d)
						{
		     		        front=rear+1;
					        break;
						}
				        vis[node[n].a[i]]=1;
					}
				}
			}  
		    if(queue[rear]==d)
			    printf("$%ld\n",ship*dis[d]*100);
		    else
				printf("NO SHIPMENT POSSIBLE\n");
			if(j==p)
				printf("\n");
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}




