#include<cstdio>
#include<queue>
using namespace std;
struct{
	int a[500],size;
}node[101];
int main()
{
	queue<int>qu;
	int b[1000],i,j,qr,n,p,q,vis[1000],s;
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
			qu.push(s);
			while(!qu.empty())
			{
				p=qu.front();
				qu.pop();
				for(i=0;i<node[p].size;i++)
				{
					q=node[p].a[i];
					if(vis[q]==0)
					{
						vis[q]=1;
						qu.push(q);
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
