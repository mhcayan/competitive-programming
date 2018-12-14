#include<stdio.h>
int main()
{
	int a[1000],p[101][101],n,i,j,k,q,s,x,y;
	while(scanf("%d",&n)&&n)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				p[i][j]=0;
		while(scanf("%ld",&x)&&x)
		{
			while(scanf("%ld",&y)&&y)
				p[x][y]=1;
		}
		for(k=1;k<=n;k++)
		{
		    for(i=1;i<=n;i++)
			{
			    for(j=1;j<=n;j++)
				{
					p[i][j]=p[i][j]|(p[i][k]&p[k][j]);
				}
			}
		}
	    scanf("%d",&q);
	    while(q--)
		{
		    scanf("%d",&s);
		    j=0;
		    for(i=1;i<=n;i++)
			{
			    if(!p[s][i])
				{
				    a[++j]=i;
				}
			}
			printf("%d",j);
		    for(i=1;i<=j;i++)
			    printf(" %d",a[i]);
		    printf("\n");
		}
	}
	return 0;
}

