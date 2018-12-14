#include<stdio.h>
struct{
	int a[500],size;
}node[101];
int main()
{
	int b[1000],i,j,qr,queue[1000],n,p,q,front,rear,vis[1000],s;
	while(scanf("%d",&n) && n)
	{
		for(i=1;i<=n;i++)
			node[i].size=0;
		while(scanf("%d",&p)&&p)
		{	
			while(scanf("%d",&q)&&q)
			{
				node[p].a[node[p].size++]=q;				
			}
		}
		scanf("%ld",&qr);
		while(qr--)
		{
			scanf("%d",&s);
			for(i=1;i<=n;i++)
				vis[i]=0;
			front=rear=1;
			queue[front] =s;
			while(front<=rear)
			{
				p=queue[front++];
				for(i=0;i<node[p].size;i++)
				{
					q=node[p].a[i];
					if(vis[q]==0)
					{
						queue[++rear]=q;
						vis[q]=1;
					}
				}
			}
			j=0;
			for(i=1;i<=n;i++)
			{
				if(vis[i]==0)
				{
					b[++j]=i;
				}
			}
			printf("%d",j);
			for(i=1;i<=j;i++)
				printf(" %d",b[i]);
			printf("\n");
		}
	}
	return 0;
}


