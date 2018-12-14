//warshall shortest path algo for weighted graph
#include<stdio.h>
#include<string.h>
long min(long a,long b);
#define INFINITY 99999;
int main()
{
	long a[100][100],p[100][100],w,t,e,v,i,j,k,n1,n2;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld %ld",&v,&e);
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		for(i=0;i<e;i++)
		{
			scanf("%ld %ld %ld",&n1,&n2,&w);
			a[n1][n2]=w;
			p[n1][n2]=w;
		}
		for(i=1;i<=v;i++)
		{
			for(j=1;j<=v;j++)
			{
				if(p[i][j]==0)
					p[i][j]=INFINITY;
			}
		}

		for(k=1;k<=v;k++)
		{
			for(i=1;i<=v;i++)
			{
				for(j=1;j<=v;j++)
				{
					p[i][j]=min(p[i][j],(p[i][k]+p[k][j]));
				}
			}
		}
		for(i=1;i<=v;i++)
		{
			for(j=1;j<=v;j++)
				printf("%ld ",p[i][j]);
		    printf("\n");
		}
	}
	return 0;
}
long min(long a,long b)
{
	if(a>b)
		return b;
	else
		return a;
}
