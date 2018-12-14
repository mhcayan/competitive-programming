#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#define clr(a) memset(a,o,sizeof(a));
#define inf 1<<30
inline int max(int a,int b)
{
	return a>b?a:b;
}
inline int min(int a,int b)
{
	return a<b?a:b;
}
using namespace std;
int main()
{
	int t=1,n,e,q,i,j,k,a[105][105],u,v,c;
	while(scanf("%d %d %d",&n,&e,&q))
	{
		if(n==0 && q==0 && e==0)
			break;
		else
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
					a[i][j]=inf;
			}
			while(e--)
			{
				scanf("%d %d %d",&u,&v,&c);
				a[u][v]=c;
				a[v][u]=c;
			}
			for(k=1;k<=n;k++)
			{
				for(i=1;i<=n;i++)
				{
					for(j=1;j<=n;j++)
						a[i][j]=min(a[i][j],max(a[i][k],a[k][j]));
				}
			}
			printf("Case #%d\n",t++);
			while(q--)
			{
				scanf("%d %d",&u,&v);
				if(a[u][v]==inf)
					printf("no path\n");
				else
					printf("%d\n",a[u][v]);
			}
			printf("\n");
		}
	}
	return 0;
}
