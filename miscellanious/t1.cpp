#include<stdio.h>
int main()
{
	int a[100][100],n,e,n1,n2,i,j,ch;
	printf("Enter no. of vertices and edges\n");
	scanf("%d %d",&n,&e);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			a[i][j]=0;
		}
	}
	printf("Enter the edges:\n");
	for(i=0;i<e;i++)
	{
		scanf("%d %d",&n1,&n2);
		a[n1][n2]=1;
		a[n2][n1]=1;
	}
	printf("ENTER YOUR CHOICE:\n\n1.neighbour checking\n2.");
	scanf("%d",&ch);
	if(ch==1)
	{
		while(scanf("%d %d",&n1,&n2)==2)
		{
			if(a[n1][n2]==1)
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}
		
