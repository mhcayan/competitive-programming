#include<stdio.h>
struct{
	int a[101],size;
}node[101];
int main()
{
	int c,t,vis1[101],vis2[101],dis1[101],dis2[101],v,e,i,n1,n2,s,d,front,rear,q[105],m,n,max;
	scanf("%d",&c);
	for(t=1;t<=c;t++)
	{
		scanf("%d %d",&v,&e);
		for(i=0;i<v;i++)
			node[i].size=0;
		for(i=0;i<e;i++)
		{
			scanf("%d %d",&n1,&n2);
			node[n1].a[node[n1].size++]=n2;
			node[n2].a[node[n2].size++]=n1;
		}
		scanf("%d %d",&s,&d);
		for(i=0;i<v;i++)
		{
			vis2[i]=0;
			vis1[i]=0;
		}
		front=rear=1;
	    q[front]=s;
 	    vis1[s]=1;
		dis1[s]=0;
	    while(front<=rear)
		{
			n=q[front++];
		    for(i=0;i<node[n].size;i++)
			{
			    m=node[n].a[i];
				if(vis1[m]==0)
				{
				    q[++rear]=m;
				    dis1[m]=1+dis1[n];
				    vis1[m]=1;
				}
			}
		}
	    front=rear=1;
	    q[front]=d;
		vis2[d]=1;
	    dis2[d]=0;
	    while(front<=rear)
		{
		    n=q[front++];
		    for(i=0;i<node[n].size;i++)
			{ 
			    m=node[n].a[i];
			    if(vis2[m]==0)
				{
					dis2[m]=1+dis2[n];
				    vis2[m]=1;
				    q[++rear]=m;
				}
			}
		}
		max=dis1[0]+dis2[0];
	    for(i=1;i<v;i++)
		{
			m=dis1[i]+dis2[i];
		    if(m>max)
			    max=m;
		}
		printf("Case %d: %d\n",t,max);
	}
	return 0;
}
		