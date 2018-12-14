#include<stdio.h>
int min(int a,int b);
int main()
{
	int w[100][100],p[100][100],i,j,k,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&w[i][j]);
			if(w[i][j]==0)
				p[i][j]=11111;
			else
			    p[i][j]=w[i][j];
		}
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
