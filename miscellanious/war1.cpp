#include<stdio.h>
#include<string.h>
int main()
{
	long a[100][100],p[100][100],t,e,v,i,j,k,n1,n2;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld %ld",&v,&e);
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		for(i=0;i<e;i++)
		{
			scanf("%ld %ld",&n1,&n2);
			a[n1][n2]=1;
			p[n1][n2]=1;
		}
		for(k=1;k<=v;k++)
		{
			for(i=1;i<=v;i++)
			{
				for(j=1;j<=v;j++)
				{
					p[i][j]=p[i][j]|(p[i][k]&p[k][j]);
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
