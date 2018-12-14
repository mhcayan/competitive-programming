#include<stdio.h>
int c[101][101];
int main()
{
	int t=1,a[100],b[100],i,j,n1,n2;
	while(scanf("%d %d",&n1,&n2))
	{
		if(n1==0 && n2==0)
			return 0;
		for(i=0;i<n1;i++)
		{
			scanf("%d",&a[i]);
			c[i][0]=0;
		}
		c[i][0]=0;
		for(j=0;j<n2;j++)
		{
			scanf("%d",&b[j]);
			c[0][j]=0;
		}
		c[0][j]=0;
		for(i=1;i<=n1;i++)
			for(j=1;j<=n2;j++)
			{
				if(a[i-1]==b[j-1])
					c[i][j]=c[i-1][j-1]+1;
				else if(c[i][j-1]>=c[i-1][j])
					c[i][j]=c[i][j-1];
				else
					c[i][j]=c[i-1][j];
			}
			printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",t++,c[n1][n2]);
	}
	return 0;
}
