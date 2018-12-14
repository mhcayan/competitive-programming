#include<stdio.h>
int a[100][100],p[100][100];
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			p[i][j]=a[i][j];
		}
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(p[i][j]||(p[i][k]==1&&p[k][j]==1))
					p[i][j]=1;
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




